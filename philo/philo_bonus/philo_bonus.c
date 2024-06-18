/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:52:45 by mnesfane          #+#    #+#             */
/*   Updated: 2022/06/21 15:05:07 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	data_init(t_data *data, int ac, char **av)
{
	data->id = 0;
	data->num_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat_num = ft_atoi (av[5]);
	else
		data->must_eat_num = -1;
	data->num_of_meals = 0;
	data->last_meal = get_time();
	data->start_time = get_time();
	data->pid = 1;
	data->j = data->num_philo;
	data->pids = malloc(sizeof(pid_t) * data->num_philo);
	sem_unlink("fork");
	data->fork = sem_open("fork", O_CREAT, S_IRWXU, data->num_philo);
	sem_unlink("must_eat");
	data->must_eat = sem_open("must_eat", O_CREAT, S_IRWXU, 0);
	sem_unlink("print");
	data->print = sem_open("print", O_CREAT, S_IRWXU, 1);
}

void	ft_print(t_data *data, char *msg)
{
	sem_wait (data->print);
	printf ("%lld [%lld] %s\n", (get_time() - data->start_time), data->id, msg);
	sem_post (data->print);
}

void	routine(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		sem_wait(data->fork);
		ft_print(data, "has taken a fork");
		sem_wait(data->fork);
		ft_print(data, "has taken a fork");
		ft_print(data, "is eating..");
		ft_usleep(data->time_eat);
		data->last_meal = get_time();
		data->num_of_meals++;
		sem_post(data->fork);
		sem_post(data->fork);
		if (data->must_eat_num && data->must_eat_num
			<= data->num_of_meals && i == 0)
		{
			sem_post(data->must_eat);
			i++;
		}
		ft_print(data, "is sleeping");
		ft_usleep(data->time_sleep);
		ft_print(data, "is thinking");
	}
}

void	*check(t_data *data)
{
	while (1)
	{
		usleep(500);
		if ((get_time() - data->last_meal) > (data->time_die))
		{
			sem_wait(data->print);
			printf("%lld %lld died\n",
				(get_time() - data->start_time), data->id);
			ft_free_all(data);
			exit(1);
		}
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = -1;
	if (!(ac == 5 || ac == 6))
	{
		printf("Error\n");
		return (0);
	}
	data_init(&data, ac, av);
	while (++i < data.num_philo && data.pid != 0)
	{
		if (data.id % 2 == 0)
			usleep(100);
		data.pid = fork();
		data.id = i + 1;
		data.pids[i] = data.pid;
		if (data.pid == 0)
			pthread_create(&data.check, NULL, (void *)check, &data);
	}
	if (data.pid == 0)
		routine(&data);
	else
		kill_all(&data);
}
