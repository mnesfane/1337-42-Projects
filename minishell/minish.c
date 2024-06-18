/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:12:12 by mnesfane          #+#    #+#             */
/*   Updated: 2022/07/18 17:55:51 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void creat_prompt()
{
	char *line;
	line = readline("minishell][:)]~> ");
	// free (line);
}

void	signal_handler(int sig)
{
	//char *line;
	if (sig == SIGINT)
	{
		creat_prompt();
		printf ("\n");
		rl_on_new_line();
		rl_redisplay();
		creat_prompt();
		
	}
	// free (line);
	// exit (0);
}

void	ctrl_signals(void)
{
	//char *line;
	
	signal (SIGINT, signal_handler);
}

int main()
{
	//char *line;
	
	ctrl_signals();
	// printf ("nik mook");
	// while (1)
	// {
	// 	ctrl_signals();
	// 	creat_prompt();
	// }
	// ctrl_signals();
	// while (1)
	// {
	// 	// free(line);
		creat_prompt();
	// 	printf ("ziiiii\n");
	// 	// exit (0);
	// }
}