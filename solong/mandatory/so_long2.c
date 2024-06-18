/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:26:10 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/14 14:24:06 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(const char *s, const char *tofind)
{
	int	i;
	int	j;

	i = 0;
	if (tofind[0] == '\0')
	{
		return ((char *)(s));
	}
	while (s[i])
	{
		j = 0;
		while (s[i + j] == tofind[j])
		{
			if (tofind[j + 1] == '\0')
				return ((char *)(s + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

int	check_map2(char *line)
{
	t_game	g;

	g.i = 0;
	g.e = 0;
	g.c = 0;
	g.p = 0;
	while (line[g.i])
	{
		if (line[g.i] != 'P' && line[g.i] != 'C' && line[g.i] != 'E'
			&& line[g.i] != '1' && line[g.i] != '0' && line[g.i] != '\n')
			return (0);
		if (line[g.i] == 'C')
			g.c++;
		if (line[g.i] == 'E')
			g.e++;
		if (line[g.i] == 'P')
			g.p++;
		g.i++;
	}
	if (g.p != 1 || g.c == 0 || g.e == 0)
		return (0);
	return (1);
}

int	valid_map(int fd, int i)
{
	if (fd == 1 && i == 1)
		return (1);
	return (ft_printf("Bad map! > recheck ur map"), 0);
}

int	sa(void)
{
	printf("You Quit!\n");
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	my;

	if (ac != 2)
		return (ft_printf("error args numb"), 0);
	else
	{
		my.fd = checkext(av[1]);
		my.line = read_map(my.fd, my.line);
		my.map = ft_split(my.line, '\n');
		my.fd = check_map(my.map, my.line);
		my.n = check_map2(my.line);
		if (valid_map(my.fd, my.n) == 0)
		{
			return (0);
			free(my.line);
			free(my.map);
		}
		print_mape(&my);
	}
}
