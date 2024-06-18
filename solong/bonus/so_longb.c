/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:48:18 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/14 14:25:34 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_longbonus.h"

char	*read_map(int fd, char *line)
{
	char	*buf;
	int		ret;

	if (!line)
		line = ft_strdup("");
	buf = malloc(2);
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		line = ft_strjoin(line, buf);
	}
	return (free(buf), line);
}

int	ft_mapelines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

int	checkext(char *av)
{
	int	fd;

	fd = open (av, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n Error 404");
		exit (0);
	}
	if (ft_strstr(av, ".ber"))
		return (fd);
	else
	{
		perror("Error\n Error 404");
		exit (0);
	}
	return (fd);
}

int	lines(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

int	check_map(char **map, char *line)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (ft_mapelines(map) != lines(line))
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1' || map[i][0] != '1')
				return (0);
			if (map[i][ft_strlen(map[i]) - 1] != '1'
				|| map[ft_mapelines(map) - 1][j] != '1')
				return (0);
			if (ft_strlen(map[i]) - 1
				!= ft_strlen(map[ft_mapelines(map) - 1]) - 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
