/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:06:03 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/23 22:23:14 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	td;
	size_t	ts;
	size_t	ret;

	i = 0;
	td = ft_strlen(dst);
	ts = ft_strlen(src);
	if (size < td)
		return (size + ts);
	else
		ret = ts + td;
	while (src[i] && td + 1 < size && size != 0)
		dst[td++] = src[i++];
	dst[td] = '\0';
	return (ret);
}
