/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:00:15 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/18 16:02:30 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *c, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (c[i] && s[i] && c[i] == s[i] && i < (n - 1))
	{
		i++;
	}
	return ((unsigned char)c[i] - (unsigned char)s[i]);
}
