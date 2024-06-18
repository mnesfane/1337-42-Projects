/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:40:33 by mnesfane          #+#    #+#             */
/*   Updated: 2022/06/21 12:40:35 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_id;
	long long		born_time;
	long long		last_eat;
	int				check_each_philosopher_must_eat;
	struct s_data	*philo_data;
	pthread_t		philo_t;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}	t_philo;

typedef struct s_data
{
	long long		died;
	long long		check_philo;
	long long		numphilos;
	long long		timetodie;
	long long		timetoeat;
	long long		timetosleep;
	long long		number_of_times_each_philosopher_must_eat;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];
}	t_data;
int			continu_check_deth(t_data *philo_data, int i);
void		destroy_mutex(t_data *philo_data);
int			check_death(t_data *philo_data);
void		smart_sleep(long long time, t_data *data);
long long	timestamp(void);
void		eating_time(t_philo *philo_data);
void		error_and_exit(void);
void		check_max_min_atoi(long long ok, long long sing);
long long	ft_atoi(char *str);
#endif