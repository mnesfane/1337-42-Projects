/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:48:16 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/24 11:51:20 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;
	size_t	k;
	size_t	x;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	x = ft_strlen(s);
	if (len > x)
		len = x;
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (i >= start && k < len)
			p[k++] = s[i];
		i++;
	}
	p[k] = '\0';
	return (p);
}
