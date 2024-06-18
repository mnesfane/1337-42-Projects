/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:12:10 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/26 20:49:21 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	signe;
	int	r;

	i = 0;
	signe = 1;
	r = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n'
		|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			signe = signe * -1 ;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9' && s[i])
	{
		r = r * 10 + s[i] - '0';
		i++;
	}
	return (r * signe);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i])
		;
	return (i);
}

int	send_byt(char *c, int pid)
{
	int	shifter;
	int	i;

	i = -1;
	shifter = -1;
	while (ft_strlen(c) >= ++i)
	{	
		shifter = -1;
		while (++shifter < 8)
		{
			if ((c[i] >> shifter) & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					return (0);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					return (0);
			}
			usleep(500);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		if ((pid <= 0 || send_byt(str, pid) == 0))
			write (1, "wrong pid a retard", 18);
	}
	else
		write (1, "retard", 6);
}
