/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:08:59 by mnesfane          #+#    #+#             */
/*   Updated: 2021/12/29 13:13:04 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long x, int count)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (x >= 16)
	{
		count = ft_putptr(x / 16, count);
		count = ft_putptr(x % 16, count);
	}
	else
	{
		write (1, &tab[x], 1);
		count++;
	}
	return (count);
}
