/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:17:32 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 16:17:39 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lexer(t_list *lexer)
{
	free_list(lexer);
}

void	free_parser(t_ast *tree)
{
	free_tree(tree->root);
	free(tree);
}

void	free_lexer_parser(t_list *lexer, t_ast *tree)
{
	free_lexer(lexer);
	free_parser(tree);
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		free(cmd->args[i++]);
	free(cmd->args);
	free_redir_list(cmd->redir);
	free(cmd);
}

void	free_2d(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}
