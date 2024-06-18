/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:53:32 by mnesfane          #+#    #+#             */
/*   Updated: 2022/07/23 23:51:01 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_cd(t_data *data)
// {
// 	int i;
// 	int j;
// 	int x;
	
// 	i = 1;
// 	j = 0;
// 	x = 0;
// 	char *pwd;
// 	char *join1;
// 	char *join2;
	
// 	if (data->split[1] != NULL)
// 		join1 = ft_strjoin("/", data->split[1]);
// 	// if (data->split[1] == "-")
// 	// {
// 	// 	data->cwd = getcwd(NULL, 0)
// 	// 	chdir("..");
	
// 	// }
// 	pwd = getcwd(NULL, 0);
// 	if (data->split[1] != NULL)
// 		join2 = ft_strjoin(pwd, join1);
// 	if (chdir (join2) == -1)
// 		printf ("cd: no such file or directory: %s\n", data->split[1]);
// 	while (data->env[j] != NULL)
// 	{
// 		if (ft_strcmp((data->env[j]), "PWD=", 3) == 0)
// 		{
// 			// printf ("%s\n", data->env[j]);
// 			// exit (0);
// 			data->env[j] = env_pwd(data);
// 			// while (data->env[x])
// 			// {
// 			// 	printf ("%s\n", data->env[x]);
// 			// 	x++;
// 			// }
// 			// ft_env(data);
// 			// exit (0);
// 		}
// 		j++;
// 	}
// 	// printf ("%s", getcwd(NULL, 0));
// 	// exit (0);
// }

void	ft_cd(t_data *data)
{
	int j;
	
	j = 0;
	char *pwd;
	char *mince;

	mince = "-";
	data->oldpwd = getcwd(NULL, 0);
	if (data->split[1][0] == '-')
	{
		chdir(data->oldpwd);
		printf ("%s\n", data->oldpwd);
	}
	if (data->split[1] != NULL  && data->split[1][0] != '-')
		if (chdir (data->split[1]) == -1)
			printf ("cd: no such file or directory: %s\n", data->split[1]);
}

// void	env_pwd(t_data *data, int j)
// {
// 	char *pwd;
// 	char *join;
	
// 	pwd = getcwd(NULL, 0);
// 	join = ft_strjoin("PWD=", pwd);
// 	// data->env[j] = join;
// 	return (join);
	
// }
// char	*env_pwd(t_data *data, int j)
// {
// 	char *pwd;
// 	char *join;
	
// 	pwd = getcwd(NULL, 0);
// 	join = ft_strjoin("PWD=", pwd);
// 	// data->env[j] = join;
// 	return (join);
	
// }