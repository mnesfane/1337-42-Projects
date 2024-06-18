/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:20 by youssama          #+#    #+#             */
/*   Updated: 2022/07/30 22:54:41 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// int	ft_env(t_cmd *cmd, char **env)
// {
// 	int	i;

// 	i = 0;
// 	if (!cmd->args[1])
// 	{
// 		while (env[i])
// 		{
// 			if (ft_strchr(env[i], '=') != -1)
// 				printf("%s\n", env[i]);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		g_data.exit_status = EXIT_FAILURE;
// 		return (ft_perror("minishell: env: Too many arguments.", NULL));
// 	}
// 	return (EXIT_SUCCESS);
// }

int	char_compaire(char *str,  char c)
{
	int j;

	j = 0;
	while (str[j])
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

void    ft_env(t_cmd *cmd, t_sh *sh)
{
    
	int i;
    
    i = 0;
	// printf ("gg");
	(void)cmd;
	while (sh->env[i] != NULL)
	{
		// if (ft_strcmp((sh->env[i]), "PWD=", 3) == 0)
		// {
		// 	printf ("PWD=%s\n", getcwd(NULL, 0));
		// 	i++;
		// }
		// else if (ft_strcmp((sh->env[i]), "OLDPWD=", 6) == 0)
		// {
		// 	if (sh->oldpwd[0] != '/')
		// 		sh->oldpwd = getcwd(NULL, 0);
		// 	printf ("OLDPWD=%s\n", sh->oldpwd);
		// 	i++;
		// }
		// else
		// {
		// }
			// if (cmd->args[1] != NULL && char_compaire(cmd->args[1] , '=') == 0)
			// 	i++;
			// else
			// {
				printf ("%s\n", sh->env[i]);
				i++;
			// }
	}
}

void	ft_unset(t_cmd *cmd, t_sh *sh)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (cmd->args[i])
	{
		while (sh->varname[j])
		{
			if (ft_strcmp(sh->varname[j], (cmd->args[i])) == 0)
			{
			// printf ("GG");
			// exit (0);
				while (sh->varname[j])
				{
					sh->varname[j] = sh->varname[j + 1];
					sh->varvalue[j] = sh->varvalue[j + 1];
					j++;
				}
				sh->varname[j] = NULL;
				sh->varvalue[j] = NULL;
				break;
			}
			// i++;
			j++;
		}
		i++;
		j = 0;
	}
	j = 0;
	while (sh->varname[j])
	{
		printf ("%s=%s\n", sh->varname[j], sh->varvalue[j]);
		j++;
	}
}