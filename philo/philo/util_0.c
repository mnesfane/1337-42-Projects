/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:40:42 by mnesfane          #+#    #+#             */
/*   Updated: 2022/06/21 12:40:44 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	long	ft_atoi(char *str)
{
	long long	sing;
	long long	ok;
	long long	i;

	ok = 0;
	i = 0;
	sing = 1;
	if (str[i] == '-')
		sing = -1;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '0'
			|| str[i + 1] == '1' || str[i + 1] == '2' || str[i + 1] == '3'
			|| str[i + 1] == '4' || str[i + 1] == '5' || str[i + 1] == '6'
			|| str[i + 1] == '7' || str[i + 1] == '8' || str[i + 1] == '9'))
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ok = (ok * 10) + str[i] - 48;
		else
			error_and_exit();
		i++;
	}
	check_max_min_atoi(ok, sing);
	return (ok * sing);
}

void	check_max_min_atoi(long long ok, long long sing)
{
	if ((ok * sing) > 2147483647 || (ok * sing) < 1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	destroy_mutex(t_data *philo_data)
{
	int	i;

	i = 0;
	while (i < philo_data->numphilos)
	{
		pthread_mutex_destroy(philo_data->philos[i].left_fork);
		pthread_mutex_destroy(philo_data->philos[i].right_fork);
		i ++;
	}
}

int	continu_check_deth(t_data *philo_data, int i)
{	
	if (philo_data->number_of_times_each_philosopher_must_eat != -1)
	{
		if (philo_data->philos[i].check_each_philosopher_must_eat
			> philo_data->number_of_times_each_philosopher_must_eat)
		{
			destroy_mutex(philo_data);
			return (1);
		}
	}
	return (0);
}
