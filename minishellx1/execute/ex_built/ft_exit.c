/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:09:14 by youssama          #+#    #+#             */
/*   Updated: 2022/07/29 00:57:04 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	number_of_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (!num)
		return (0);
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_args_for_exit(char **args)
{
	if (args[0] && !args[1])
	{
		free_parser(g_data.tree);
		exit(EXIT_SUCCESS);
	}
	if (number_of_args(args) > 2)
	{
		free_parser(g_data.tree);
		printf("minishel: exit: too many arguments\n");
		g_data.exit_status = 1;
		exit (1);
	}
	if (!ft_isnum(args[1]))
	{
		free_parser(g_data.tree);
		printf("exit: %s: numeric argument required\n", args[1]);
		g_data.exit_status = 255;
		exit(255);
	}
	return (0);
}

// int	ft_exit(t_cmd *cmd, char **env)
// {
// 	(void) env;
// 	free_lexer(g_data.lex);
// 	del_env(g_data.ev);
// 	if (g_data.alloc)
// 		free_2d(env);
// 	printf("exit\n");
// 	if (check_args_for_exit(cmd->args))
// 		return (1);
// 	g_data.exit_status = ft_atoi(cmd->args[1]);
// 	free_parser(g_data.tree);
// 	exit(g_data.exit_status);
// 	return (EXIT_SUCCESS);
// }

void	ft_exit(void)
{
	printf ("exit\n");
	exit (0);
}