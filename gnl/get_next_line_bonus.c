/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 21:23:55 by mnesfane          #+#    #+#             */
/*   Updated: 2021/12/27 11:34:48 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *line)
{
	int		ret;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			free(line);
			return (NULL);
		}
		buf[ret] = '\0';
		line = ft_strjoin(line, buf);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buf);
	return (line);
}

char	*get_line_rest(int fd, char **line, char *str)
{
	char	*tmp;

	if (!ft_strchr(*line, '\n'))
		*line = read_line(fd, *line);
	if (*line == NULL || **line == 0)
	{
		free (*line);
		*line = NULL;
		return (NULL);
	}
	tmp = *line;
	str = get_line(*line);
	if (ft_strchr(*line, '\n') && *(ft_strchr(*line, '\n') + 1))
		*line = ft_strdup(ft_strchr(tmp, '\n') + 1);
	else
		*line = NULL;
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*line[10240];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	if (!line[fd])
		line[fd] = ft_strdup("");
	str = NULL;
	str = get_line_rest(fd, &line[fd], str);
	return (str);
}
