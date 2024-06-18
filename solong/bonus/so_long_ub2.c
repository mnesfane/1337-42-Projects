/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ub2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:14:35 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/12 16:14:50 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_longbonus.h"

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

static void	ft_free(char **str, int k)
{
	while (k--)
		free(str[k]);
	free(str);
}

static char	**subsrtings(char **str, char const *s, char c, int count)
{
	int	len;
	int	k;
	int	i;

	i = 0;
	len = 0;
	k = 0;
	while (s[i] && k < count)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		str[k++] = (char *)ft_calloc(sizeof(char), (len + 1));
		len = 0;
	}
	if (k > 0 && !str[k - 1])
	{
		ft_free(str, k - 1);
		return (0);
	}
	return (str);
}

int	wdc(char const *s, char c)
{
	int	wdc;
	int	i;

	i = 0;
	wdc = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wdc++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (wdc);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		len;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = -1;
	if (s == NULL)
		return (NULL);
	len = wdc(s, c);
	str = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!str)
		return (NULL);
	subsrtings(str, s, c, len);
	while (s[i] && j + 1 < len)
	{
		if (s[i] != c && ++j >= 0)
			while (s[i] != c && s[i])
				str[j][k++] = s[i++];
		while (s[i] == c && s[i++])
			k = 0;
	}
	return (str);
}
