/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:21:39 by mhanda            #+#    #+#             */
/*   Updated: 2022/07/30 22:28:02 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


// void	execute(t_ast_node *ptr, char ***env, int cmd_count, t_elem *lexer_head)
// {
// 	int			fd[2];
// 	int			pid;
// 	static int	count;

// 	pid = 0;
// 	if (ptr->type == CMD)
// 	{
// 		pid = exec_builtins_execve(ptr, env, lexer_head, fd);
// 		count++;
// 	}
// 	else if (ptr->type == PIPE)
// 	{
// 		if (pipe(fd) < 0)
// 			return ;
// 		if (ptr->content->pipe->right->type == CMD)
// 			dup_fd(&ptr->content->pipe->right->content->cmd->fd.out, fd[1]);
// 		else if (ptr->content->pipe->right->type == PIPE)
// 			dup_fd(find_right_left(ptr), fd[1]);
// 		dup_fd(&ptr->content->pipe->left->content->cmd->fd.in, fd[0]);
// 		execute(ptr->content->pipe->right, env, cmd_count, lexer_head);
// 		execute(ptr->content->pipe->left, env, cmd_count, lexer_head);
// 		close(fd[0]);
// 		close(fd[1]);
// 	}
// 	check_last_pid(pid, count, cmd_count);
// }

void	start_exec(t_cmd *cmd, t_sh *sh)
{
	if (!ft_strncmp((cmd->args[0]), "export", 2))
		ft_export(cmd, sh);
	// if (!ft_strncmp((cmd->args[0]), "cd", 2))
	// 	ft_cd();
	// if (!ft_strncmp((cmd->args[0]), "echo", 4))
	// 	ft_echo();
	if (!ft_strncmp((cmd->args[0]), "exit", 4))
		ft_exit();
	if (!ft_strncmp((cmd->args[0]), "pwd", 3))
		ft_pwd();
	if (!ft_strncmp((cmd->args[0]), "env", 3))
		ft_env(cmd, sh);	
	if (!ft_strncmp((cmd->args[0]), "unset", 4))
		ft_unset(cmd, sh);
}

void split_envtab(t_env *ev, char **env, t_sh *sh)
{
	int	i;

	i = 0;
	ev = create_env(env);
	split_ev(ev, sh);
	// while (sh->varvalue[i])
	// {
	// 	printf ("%s\n", sh->varvalue[i]);
	// 	i++;
	// }
}

void	execute(t_ast_node *ptr, char ***env, int cmd_count, t_elem *lexer_head)
{
	t_sh sh;
	t_env	*ev;
	int	i;

	i = 0;
	(void)cmd_count;
	(void)lexer_head;
	
	sh.env = *env;
	ev = NULL;
	split_envtab(ev, *env, &sh);
	start_exec(ptr->content->cmd, &sh);
}
