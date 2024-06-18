/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:17:58 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/23 22:21:26 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *s1, const char *s2, size_t t)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = ft_strlen(s2);
	if (t == 0)
		return (x);
	while (s2[i] && i < t - 1)
	{
		s1[i] = s2[i];
			i++;
	}
	s1[i] = '\0';
	return (x);
}
