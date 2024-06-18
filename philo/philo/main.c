/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:39:58 by mnesfane          #+#    #+#             */
/*   Updated: 2022/06/21 15:25:05 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parc(char **av, int ac, t_data *philo_data)
{
	int	i;

	i = 0;
	philo_data->died = 0;
	philo_data->check_philo = 0;
	philo_data->numphilos = ft_atoi(av[1]);
	philo_data->timetodie = ft_atoi(av[2]);
	philo_data->timetoeat = ft_atoi(av[3]);
	philo_data->timetosleep = ft_atoi(av[4]);
	if (ac == 6)
		philo_data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		philo_data->number_of_times_each_philosopher_must_eat = -1;
	while (i < philo_data->numphilos)
	{
		pthread_mutex_init(&philo_data->forks[i], NULL);
		i ++;
	}
}

void	get_id_fork(t_data *philo_data)
{
	int	i;

	i = 0;
	while (i < philo_data->numphilos)
	{
		philo_data->philos[i].last_eat = 0;
		philo_data->philos[i].check_each_philosopher_must_eat = 0;
		philo_data->philos[i].philo_id = i + 1;
		philo_data->philos[i].philo_data = philo_data;
		philo_data->philos[i].left_fork = &philo_data->forks[i];
		philo_data->philos[i].born_time = timestamp();
		if (i == philo_data->numphilos - 1)
			philo_data->philos[i].right_fork = &philo_data->forks[0];
		else
			philo_data->philos[i].right_fork = &philo_data->forks[i + 1];
		i++;
	}
}

void	*philo_routin(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->philo_id % 2 == 0)
		usleep(100);
	while (1)
	{
		eating_time(ph);
	}
	return (NULL);
}

int	creat_thread(t_data *philo_data)
{
	int	i;

	i = 0;
	while (i < philo_data->numphilos)
	{
		if (pthread_create(&philo_data->philos[i].philo_t, NULL,
				&philo_routin, &philo_data->philos[i]))
		{
			write(2, "Error", 5);
			return (1);
		}
		philo_data->philos[i].last_eat = timestamp();
		i++;
	}
	if (check_death(philo_data) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	philo_data;

	if (ac > 6 || ac < 5)
		return (0);
	parc(av, ac, &philo_data);
	get_id_fork(&philo_data);
	if (creat_thread(&philo_data) == 1)
		return (0);
}
