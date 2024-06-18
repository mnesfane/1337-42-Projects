/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:48:20 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 16:30:35 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data)
{
	data->exit_status = 0;
	data->which = 0;
	data->pid = 0;
	data->tree = NULL;
	data->ev = NULL;
	data->alloc = 0;
}

int	main(int c, char **v, char **env)
{
	(void)v;
	if (c != 1 || !*env)
		return (1);
	init_data(&g_data);
	init_sigaction(&g_data);
	lunch_program(env);
}
