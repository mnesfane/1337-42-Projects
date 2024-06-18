/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:20:56 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 16:26:11 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
		i++;
	}
	return (dst);
}

void	*ft_realloc(void *ptr, int old_size, int new_size)
{
	void	*new;

	new = malloc(sizeof(void) * new_size);
	if (!new)
		return (NULL);
	new = memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
