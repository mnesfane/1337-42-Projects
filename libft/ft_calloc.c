/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:45:02 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/24 09:57:29 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t sizeitems)
{
	char			*ptr;
	unsigned int	k;

	k = nitems * sizeitems;
	ptr = malloc(k);
	if (ptr == 0)
		return (NULL);
	ft_memset(ptr, 0, k);
	return (ptr);
}
