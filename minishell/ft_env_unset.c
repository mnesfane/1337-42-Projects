/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:19:54 by mnesfane          #+#    #+#             */
/*   Updated: 2022/07/24 00:21:17 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void    ft_env(t_data *data)
{
    
	int i;
    
    i = 0;
	while (data->env[i] != NULL)
	{
		if (ft_strcmp((data->env[i]), "PWD=", 3) == 0)
		{
			printf ("PWD=%s\n", getcwd(NULL, 0));
			i++;
		}
		else if (ft_strcmp((data->env[i]), "OLDPWD=", 6) == 0)
		{
			if (data->oldpwd[0] != '/')
				data->oldpwd = getcwd(NULL, 0);
			printf ("OLDPWD=%s\n", data->oldpwd);
			i++;
		}
		else
		{
			if (char_compaire(data->split[i], '=') == 0)
				i++;
			else
			{
				printf ("%s\n", data->env[i]);
				i++;
			}
		}	
	}
}

void	ft_unset(t_data *data)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (data->split[i])
	{
		while (data->env[j])
		{
			if (ft_strcmp(data->env[j], (data->split[i]), ft_strlen(data->split[i]) - 1) == 0)
			{
				while (data->env[j])
				{
					data->env[j] = data->env[j + 1];
					j++;
				}
				data->env[j] = NULL;
				break;
			}
			// i++;
			j++;
		}
		i++;
		j = 0;
	}
	// j = 0;
}

void	addto_var(t_data *data, int j)
{
	char **ex;
	int		i;

	i = 0;
	if (ft_strstr(data->split[j], "+=") == 1) //ss[0]
	{
		while (data->env[i])
		{
			data->ss = ft_split(data->env[i], '=');
			if (ft_strcmp(data->ss[0], data->split[j], ft_strlen(data->ss[0]) - 1) == 0)
			{
				data->r = i;
				ex = ft_split(data->split[j], '+');
				if (!ft_strcmp(data->ss[0], data->env[i], ft_strlen(data->ss[0]) - 1))
					data->ss[1] = ft_strjoin(data->ss[1], (ex[1] + 1));
					printf ("%s\n", data->ss[1]);
					exit (0);
			}
			i++;
		}
	}
}

void	export_args(t_data *data)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (data->split[i])
	{
		if (data->split[i][0] == '$' || data->split[i][0] == '#')
		{
				if (i == 1)
					data->split[1] = NULL;
				else
					return ;
		}
		if (data->split[i][0] != '_' && ft_isalpha(data->split[i][0]) == 0)
		{
			printf("export: `%s': not a valid identifier\n", data->split[i]);
			return ;
		}
		addto_var(data, i);
		if (char_compaire(data->split[i] , '+'))
		{
			printf("export: `%s': not a valid identifier\n", data->split[i]);
			return ;
		}
		while (data->env[j])
			j++;
		data->env[j] = data->split[i];
		data->env[++j] = NULL;
		i++;
	}
}	

void	ft_export(t_data *data)
{
	int i;
    
    i = 0;
	char **ss;
	export_args(data);
	while (data->env[i] != NULL && data->split[1] == NULL)
	{
		ss = ft_split(data->env[i], '=');
		if (ft_strcmp((data->env[i]), "PWD=", 3) == 0)
			printf ("declare -x PWD=\"%s\"\n", getcwd(NULL, 0));
		else if (ft_strcmp((data->env[i]), "OLDPWD=", 6) == 0)
		{
			if (data->oldpwd[0] != '/')
				data->oldpwd = getcwd(NULL, 0);
			printf ("declare -x OLDPWD=\"%s\"\n", data->oldpwd);
		}
		else
		{
			if (ss[1] == NULL)
				printadded_var(data, i, ss);
			else
				printf ("declare -x %s=\"%s\"\n", ss[0], ss[1]);
		}
		i++;	
	}
}

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

void	printadded_var(t_data *data, int i, char **ss)
{
	if (char_compaire(data->env[i], '=') == 1)
		printf ("declare -x %s=\"\"\n", ss[0]);
	else
		printf ("declare -x %s\n", ss[0]);
}