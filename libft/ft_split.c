/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:02:02 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/24 10:56:16 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_free(char **str, int k)
{
	while (k--)
		free(str[k]);
	free(str);
}

char	**subsrtings(char **str, char const *s, char c, int count)
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
