/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:34:39 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/24 10:15:37 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	const char	*p1;
	const char	*p2;

	p1 = str1;
	p2 = str2;
	if (len == 0)
		return (0);
	while (*p1 == *p2 && len-- > 1)
	{
		p1++;
		p2++;
	}
	return ((unsigned char)*p1 - (unsigned char)*p2);
}
