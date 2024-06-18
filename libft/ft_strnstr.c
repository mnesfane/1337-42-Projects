/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:18:07 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/25 15:49:52 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (tofind[0] == '\0')
	{
		return ((char *)(s));
	}
	while (s[i])
	{
		j = 0;
		while (s[i + j] == tofind[j] && i + j < len)
		{
			if (tofind[j + 1] == '\0')
				return ((char *)(s + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
