/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:36:29 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 16:25:32 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_redir(enum e_token type)
{
	return (type == REDIR_IN || type == REDIR_OUT
		|| type == DREDIR_OUT || type == HERE_DOC);
}

void	count_quotes_redir_args(t_elem **elem, enum e_token type, int *i)
{
	if (type == DOUBLE_QUOTE || type == QOUTE)
	{
		(*elem) = (*elem)->next;
		while ((*elem) && (*elem)->type != type)
			(*elem) = (*elem)->next;
		(*i)++;
	}
	else if (is_redir(type))
	{
		while ((*elem)->type != WORD && (*elem)->type != ENV)
			(*elem) = (*elem)->next;
		(*elem) = (*elem)->next;
	}
}

int	count_args(t_elem *elem)
{
	t_elem	*tmp;
	int		i;

	i = 0;
	tmp = elem;
	while (tmp && tmp->type != PIPE_LINE)
	{
		if (tmp->type == WORD || tmp->type == ENV)
			i++;
		else if (tmp->type == DOUBLE_QUOTE || tmp->type == QOUTE
			|| is_redir(tmp->type))
			count_quotes_redir_args(&tmp, tmp->type, &i);
		if (tmp)
			tmp = tmp->next;
	}
	return (i);
}
