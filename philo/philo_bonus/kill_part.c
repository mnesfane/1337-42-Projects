/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:52:37 by mnesfane          #+#    #+#             */
/*   Updated: 2022/06/21 14:52:39 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_kill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		kill(data->pids[i], SIGKILL);
		i++;
	}
	ft_free_all(data);
	exit (0);
}

void	kill_all(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (1)
	{
		if (data->must_eat_num != -1)
		{
			while (1)
			{
				sem_wait(data->must_eat);
				j++;
				if (j == data->num_philo)
					ft_kill(data);
			}
		}
		waitpid(-1, &i, 0);
		if (i != 0)
		{
			ft_kill(data);
			break ;
		}
	}
}

void	ft_free_all(t_data *data)
{
	if (data->pid != 0)
	{
		sem_unlink("fork");
		sem_unlink("print");
		sem_unlink("must_eat");
		sem_close(data->fork);
		sem_close(data->print);
		sem_close(data->must_eat);
		free(data->pids);
	}
	else
		free(data->pids);
}
