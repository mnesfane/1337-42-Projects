/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_b_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:52:58 by mnesfane          #+#    #+#             */
/*   Updated: 2022/06/21 14:53:00 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h" 

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

long long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() < start + time)
		usleep(50);
}
