/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 05:39:12 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 16:28:48 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	tokenize_redir(t_list *tokens, char *line, int i, enum e_state *state)
{
	int	j;

	j = i;
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
			add_tail(tokens, new_elem(line + (i++), 2, HERE_DOC, *state));
		else
			add_tail(tokens, new_elem(line + (i), 1, REDIR_IN, *state));
		i++;
	}
	else if (line[i] == '>')
	{
		if (line[i + 1] == '>')
			add_tail(tokens, new_elem(line + (i++), 2, DREDIR_OUT, *state));
		else
			add_tail(tokens, new_elem(line + (i), 1, REDIR_OUT, *state));
		i++;
	}
	return (i - j);
}

int	tokenize(t_list *tokens, char *line, int i, enum e_state *state)
{
	if (!in_charset(line[i]))
		i += get_word(tokens, line + i, *state);
	else if (line[i] == '\'')
		quotes_state(tokens, line + (i++), state, 1);
	else if (line[i] == '\"')
		quotes_state(tokens, line + (i++), state, 2);
	else if (line[i] == '$')
	{
		if (in_charset(line[i + 1]) || line[i + 1] == '=')
		{
			add_tail(tokens, new_elem(line + i, 1, WORD, *state));
			i++;
		}
		else
			i += get_env_var(tokens, line + i, *state);
	}
	else if (line[i] == '>' || line[i] == '<')
		i += tokenize_redir(tokens, line, i, state);
	else if (line[i] == '|')
		add_tail(tokens, new_elem(line + (i++), 1, PIPE_LINE, *state));
	else if (ft_isspace(line[i]))
		add_tail(tokens, new_elem(line + (i++), 1, WHITE_SPACE, *state));
	return (i);
}

t_list	*lexer(char *line)
{
	int				i;
	t_list			*tokens;
	enum e_state	state;

	i = 0;
	state = GENERAL;
	tokens = NULL;
	tokens = init_list(tokens);
	if (tokens)
	{
		while (line[i])
		{
			i = tokenize(tokens, line, i, &state);
		}
	}
	free(line);
	return (tokens);
}
