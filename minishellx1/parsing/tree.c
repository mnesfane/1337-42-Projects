/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 04:28:57 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 11:12:22 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*init_tree(t_ast *tree)
{
	tree = malloc(sizeof(t_ast));
	if (!tree)
		return (NULL);
	tree->root = NULL;
	return (tree);
}

t_ast_node	*create_cmd_node(char **args, char **env, t_redir_list *redir)
{
	t_ast_node	*node;

	node = malloc(sizeof(t_ast_node));
	node->content = malloc(sizeof(t_union));
	node->content->cmd = malloc(sizeof(t_cmd));
	if (!node || !node->content || !node->content->cmd)
		return (NULL);
	node->type = CMD;
	node->content->cmd->args = args;
	node->content->cmd->env = env;
	node->content->cmd->redir = redir;
	node->content->cmd->fd.in = 0;
	node->content->cmd->fd.out = 1;
	return (node);
}

void	free_tree(t_ast_node *node)
{
	if (node->type == CMD)
	{
		free_cmd(node->content->cmd);
		free(node->content);
		free(node);
	}
	else if (node->type == PIPE)
	{
		free_tree(node->content->pipe->right);
		free_tree(node->content->pipe->left);
		free(node->content->pipe);
		free(node->content);
		free(node);
	}
}
