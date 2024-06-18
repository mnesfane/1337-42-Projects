/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:53:07 by mnesfane          #+#    #+#             */
/*   Updated: 2022/07/23 23:18:26 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
		i++;
	return (s1[i] - s2[i]);
}

void	*ft_memset(void *str, int c, size_t len)
{
	char	*p;

	p = str;
	while (len-- > 0)
	{
		*p = c;
		p++;
	}
	return (str);
}

void	*ft_calloc(size_t nitems, size_t sizeitems)
{
	char			*ptr;
	unsigned int	k;

	k = nitems * sizeitems;
	ptr = malloc(k);
	if (ptr == 0)
	{
		free (ptr);
		return (NULL);
	}
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

char	**ft_split(char *s, char c)
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
