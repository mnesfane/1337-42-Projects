/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:55:20 by mnesfane          #+#    #+#             */
/*   Updated: 2021/12/26 21:44:27 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(char *)(s + i))
	{
		if (*(char *)(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (s1[j])
	{
		p[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		p[i++] = s2[j++];
	}
	p[i] = '\0';
	free (s1);
	s1 = NULL;
	return (p);
}

char	*ft_strdup(char *str)
{
	unsigned int	k;
	unsigned int	i;
	char			*p;

	i = 0;
	k = ft_strlen((char *)str) + 1;
	p = (char *)malloc(k * sizeof(char));
	if (!p)
		return (NULL);
	if (!str)
	{
		str[i] = '\0';
		return (str);
	}
	while (str && k-- > 0)
	{
		p[i] = str[i];
		i++;
	}
	return (p);
}

char	*get_line( char *line)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (line[j] != '\n' && line[j])
		j++;
	str = (char *)malloc(j + 2);
	while (i < j + 1)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
