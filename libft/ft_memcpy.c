/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:03:45 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/24 10:16:54 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>
#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*cp_dst;
	char	*cp_src;

	i = 0;
	cp_dst = (char *)dst;
	cp_src = (char *)src;
	if (cp_src == NULL && cp_dst == NULL)
		return (NULL);
	while (i < len)
	{
		cp_dst[i] = cp_src[i];
		i++;
	}
	return (dst);
}
