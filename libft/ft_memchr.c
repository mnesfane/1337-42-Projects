/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:37:50 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/24 10:08:08 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	while (len-- > 0)
	{
		if (*(char *)str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
