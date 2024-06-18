/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:16:09 by mnesfane          #+#    #+#             */
/*   Updated: 2022/07/21 01:38:56 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_echo_n(t_data *data)
{
	int i;
	
	i = 2;
	// printf ("%d", data->i);
	// 		exit (0);
	while (data->split[i] != NULL)
	{
		printf ("%s", data->split[i]);
		if (i < data->i - 1)
			printf (" ");
		i++;
	}	
}
void ft_echo_1(t_data *data)
{
	int i;
	
	i = 1;
	// printf ("%d", data->i);
	// 		exit (0);
	while (data->split[i] != NULL)
	{
		printf ("%s", data->split[i]);
		if (i < data->i - 1)
			printf (" ");
		i++;
	}	
}

void ft_echo(t_data *data)
{
	int i;

	i = 1;
	// while (!data->split[i])
	// {
		if (!ft_strcmp((data->split[1]), "-n", 2))
			ft_echo_n(data);
		else
		{
			ft_echo_1(data);
			printf ("\n");
		}	
	// }
	exit (1);
}

void	ft_exit(void)
{
	printf ("exit\n");
	exit (0);
}

void	ft_pwd(void)
{
	char *pwd;

	pwd = getcwd(NULL, 0);
	
	printf ("%s\n", pwd);
}