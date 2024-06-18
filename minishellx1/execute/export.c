/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:43:40 by mnesfane          #+#    #+#             */
/*   Updated: 2022/07/30 22:54:38 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	addto_var(t_cmd *cmd, t_sh *sh, int i)
{
	char **ex;
	int	j;

	j = 0;
    while (sh->env[j])
    {
        // data->ss = ft_split(sh->env[i], '=');
        ex = ft_split(cmd->args[i], "+");
        if (ft_strncmp(sh->varname[j], cmd->args[i], ft_strlen(sh->varname[j]) - 1) == 0)
        {
           sh->varvalue[j] = ft_strjoin(sh->varvalue[j], ex[1] + 1);
           return ;
            // printf ("%s", sh->varvalue[j]);
            // exit (0);
        }
        j++;
    }
	sh->varname[j] = ex[0];
	sh->varvalue[j] = ex[1] + 1;
	sh->varname[++j] = NULL;
	sh->varvalue[++j] = NULL;
}

int	export_args(t_cmd *cmd, t_sh *sh, int i)
{
	int j;
	int s;
	int f;

	j = 0;
	f = 0;
	if (cmd->args[i][0] == '$' || cmd->args[i][0] == '#')
		return 0;
	if (cmd->args[i][0] != '_' && ft_isalpha(cmd->args[i][0]) == 0)
	{
		printf("export: `%s': not a valid identifier\n", cmd->args[i]);
		return 0;
	}
	if (ft_strchr(cmd->args[i] , '=') >= 0)
	{
		s = ft_strchr(cmd->args[i] , '=');
		while (f < s - 1)
		{
			if (cmd->args[i][f] == '+')
				return (printf("export: `%s': not a valid identifier\n", cmd->args[i]), 0);
			f++;
		}
		if (s == ft_strlen(cmd->args[i]) - 1)
			return (add_avarname(cmd , sh, i), 0);
		else if (ft_strstr(cmd->args[i], "+="))
			return (addto_var(cmd, sh, i), 0);
	}
	else if (ft_strchr(cmd->args[i] , '+') >= 0 && ft_strchr(cmd->args[i] , '=') == -1)
		return (printf("export: `%s': not a valid identifier\n", cmd->args[i]), 0);
	else if (ft_strchr(cmd->args[i] , '=') == -1)
		return (add_avarname(cmd , sh, i), 0);
	return (add_var(cmd , sh, i), 1);
}

void add_var(t_cmd *cmd, t_sh *sh ,int i)
{
	int j;
	char **ex;

	j =0;
	ex = ft_split(cmd->args[i], "=");
	while (sh->varname[j])
		j++;
	sh->varname[j] = ex[0];
	sh->varvalue[j] = ex[1];
	sh->varname[++j] = NULL;
	sh->varvalue[++j] = NULL;
		
}
void add_avarname(t_cmd *cmd, t_sh *sh ,int i)
{
	int j;

	j =0;
	while (sh->varname[j])
		j++;
	sh->varname [j] = cmd->args[i];
	sh->env[j] = cmd->args[i];
	sh->varname [++j] = NULL;
	sh->env[++j] = NULL;
		
}

// void add_vartoshenv(t_cmd *cmd, t_sh *sh, int i)
// {
// 	int j;

// 	j = 0;
// 	while (sh->env[j])
// 		j++;
// 	sh->env[j] = cmd->args[i];
// 	sh->env[++j] = NULL;
// 	j = 0;
// 	while (sh->env[j])
// 	{
// 		printf ("%s\n", sh->env[j]);
// 		j++;
// 	}
// 	exit (0);
// }   
void	ft_export(t_cmd *cmd, t_sh *sh)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	j = 1;
	// while (cmd->args[j])
	// {
    // 	export_args(cmd, sh, j);
	// 	j++;
	// }
	j = 0;
	while (sh->varname[j])
	{
		printf ("/%s=%s/\n", sh->varname[j], sh->varvalue[j]);
		j++;
	}
	(void)cmd;
	exit (0);
	while (sh->varname[i])
	{
		if (sh->varvalue[i] == NULL)
		{
			if (ft_strchr(sh->varname[i], '=') >= 0)
				printf ("declare -x %s\"\"\n", sh->varname[i]);
			else if (ft_strchr(sh->varname[i] , '=') == -1)
				printf ("declare -x %s\n", sh->varname[i]);
		}
		else
			printf ("declare -x %s=\"%s\"\n", sh->varname[i], sh->varvalue[i]);
		i++;
	}
	// while(sh->env[x])
	// {
	// 	printf ("%s\n", sh->env[x]);
	// 	x++;
	// }
	
}
