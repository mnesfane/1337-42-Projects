/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:33:37 by mnesfane          #+#    #+#             */
/*   Updated: 2021/12/29 13:05:02 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int x, int nature, int count)
{
	char	*tab;

	if (nature == 0)
		tab = "0123456789abcdef";
	else if (nature == 1)
		tab = "0123456789ABCDEF";
	if (x >= 16)
	{
		count = ft_puthexa(x / 16, nature, count);
		count = ft_puthexa(x % 16, nature, count);
	}
	else
	{
		write (1, &tab[x], 1);
		count++;
	}
	return (count);
}
