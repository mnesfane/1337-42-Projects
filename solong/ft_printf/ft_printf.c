/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:09:54 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/08 19:47:51 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print(va_list args, const char *fp, int count, int i)
{
	if (fp[i] == 'd' || fp[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (fp[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (fp[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (fp[i] == 'p')
	{
		write(1, "0x", 2);
		count = ft_putptr(va_arg(args, unsigned long), count + 2);
	}
	else if (fp[i] == 'x')
		count = ft_puthexa(va_arg(args, unsigned int), 0, count);
	else if (fp[i] == 'X')
		count = ft_puthexa(va_arg(args, unsigned int), 1, count);
	else if (fp[i] == 'u')
		count += ft_putnbru(va_arg(args, unsigned int));
	else if (fp[i] == '%')
		count += ft_putchar('%');
	else if (fp[i])
		count += ft_putchar(fp[i]);
	return (count);
}

int	ft_printf(const char *fp, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, fp);
	while (fp[i])
	{
		if (fp[i] == '%')
		{
			i++;
			count = print(args, fp, count, i);
		}
		else
			count += ft_putchar(fp[i]);
		if (!fp[i])
			break ;
		i++;
	}
	va_end(args);
	return (count);
}
