/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:45:39 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/27 15:23:24 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_p = 0;

void	reset(int si_pid, char *print, int *i)
{
	g_p = si_pid;
	*print = 0;
	*i = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar('0' + nb);
}

void	handler(int c, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	print;

	(void)context;
	if (g_p != info->si_pid)
		reset(info->si_pid, &print, &i);
	if (i <= 8)
	{
		if (c == SIGUSR2)
			print = ((print) | (1 << i));
		i++;
	}
	if (i == 8)
	{
		write(1, &print, sizeof(char));
		print = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	s;

	write (1, "  PID :  ", 9);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = &handler;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
		pause();
	return (0);
}
