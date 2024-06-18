/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:04:57 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/22 18:10:43 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i-- > 0)
	{
		if (*(char *)(s + i) == (char)c)
		{
			return ((char *)(s + i));
		}
	}
	i = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
