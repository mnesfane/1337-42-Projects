/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:40:50 by mnesfane          #+#    #+#             */
/*   Updated: 2022/06/21 12:40:53 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_time(t_philo *philo_data)
{
	pthread_mutex_lock(philo_data->left_fork);
	printf("[%d] %lld has taken a fork\n", philo_data->philo_id,
		timestamp() - philo_data->born_time);
	pthread_mutex_lock(philo_data->right_fork);
	printf("[%d] %lld has taken a fork\n", philo_data->philo_id,
		timestamp() - philo_data->born_time);
	printf("[%d] %lld is eating\n", philo_data->philo_id,
		timestamp() - philo_data->born_time);
	smart_sleep(philo_data->philo_data->timetoeat, philo_data->philo_data);
	philo_data->check_each_philosopher_must_eat ++;
	philo_data->last_eat = timestamp();
	pthread_mutex_unlock(philo_data->left_fork);
	pthread_mutex_unlock(philo_data->right_fork);
	printf("[%d] %lld is sleeping\n", philo_data->philo_id,
		timestamp() - philo_data->born_time);
	smart_sleep(philo_data->philo_data->timetosleep, philo_data->philo_data);
	printf("[%d] %lld is thinking\n", philo_data->philo_id,
		timestamp() - philo_data->born_time);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	smart_sleep(long long time, t_data *data)
{
	long long	i;

	i = timestamp();
	while (!(data->died))
	{
		if (time_diff(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}

int	check_death(t_data *philo_data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (time_diff(philo_data->philos[i].last_eat, timestamp())
			> philo_data->timetodie)
		{
			printf("[%d] %lld died \n", philo_data->philos[i].philo_id,
				time_diff(philo_data->philos[i].last_eat, timestamp()));
			destroy_mutex(philo_data);
			return (1);
		}
		if (continu_check_deth(philo_data, i) == 1)
			return (1);
		if (i == (philo_data->numphilos - 1))
			i = -1;
		i++;
		usleep(100);
	}
	return (1);
}
