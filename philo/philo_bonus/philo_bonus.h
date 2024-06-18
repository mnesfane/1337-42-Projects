/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:52:51 by mnesfane          #+#    #+#             */
/*   Updated: 2022/06/21 14:52:53 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<string.h>
# include<pthread.h>
# include<sys/time.h>
# include<fcntl.h>
# include<signal.h>
# include<sys/stat.h>
# include<semaphore.h>

typedef struct s_data
{
	long long	id;
	long long	num_philo;
	long long	time_die;
	long long	time_eat;
	long long	time_sleep;
	long long	must_eat_num;
	long long	num_of_meals;
	long long	j;
	long long	last_meal;
	long long	start_time;
	pid_t		pid;
	pid_t		*pids;
	sem_t		*fork;
	sem_t		*print;
	sem_t		*must_eat;
	pthread_t	check;
}	t_data;
void		ft_free_all(t_data *data);
void		kill_all(t_data *data);
void		ft_kill(t_data *data);
void		ft_usleep(long long time);
long long	get_time(void);
void		ft_usleep(long long time);
long long	ft_atoi(char *str);
void		error_and_exit(void);
void		check_max_min_atoi(long long ok, long long sing);
#endif