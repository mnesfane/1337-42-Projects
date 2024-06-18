/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:53:08 by mnesfane          #+#    #+#             */
/*   Updated: 2022/07/24 00:02:47 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_exec(t_data *data)
{
	int i;

	i = 0;
	if (!ft_strcmp((data->split[i]), "export", 2))
		ft_export(data);
	if (!ft_strcmp((data->split[i]), "cd", 2))
		ft_cd(data);
	if (!ft_strcmp((data->split[i]), "echo", 4))
		ft_echo(data);
	if (!ft_strcmp((data->split[i]), "exit", 4))
		ft_exit();
	if (!ft_strcmp((data->split[i]), "pwd", 3))
		ft_pwd();
	if (!ft_strcmp((data->split[i]), "env", 3))
		ft_env(data);
	if (!ft_strcmp((data->split[i]), "unset", 4))
		ft_unset(data);
}

void creat_prompt(t_data *data)
{
	data->line = readline("minishell][:)]~> ");
	if (data->line == NULL)
	{
		printf("Quit\n");
		exit (1);
	}
	add_history(data->line);
	// free (line);
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf ("\n");
        rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signals()
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

int main (int ac, char **av, char **ev)
{
    t_data data;
	

		// printf ("%d", data.i);
		// exit (0);
	data.env = ev;
    while(1)
    {
        signals();
        creat_prompt(&data);
		data.split = ft_split(data.line, ' ');
		while (data.split[data.i] != NULL)
			data.i++;
		// printf ("%d", i);
		// exit (0);
		if (data.i > 0)
		{
			start_exec(&data);
		}
		data.i = 0;
    }
    
}