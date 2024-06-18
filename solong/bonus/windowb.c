/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:36:26 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/12 16:24:33 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_longbonus.h"

static size_t	ft_len(int index)
{
	int	len;

	len = 0;
	if (index <= 0)
	{
		len++;
	}
	while (index != 0)
	{
		len++;
		index = index / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	index;
	char	*str;

	len = ft_len(n);
	index = n;
	str = malloc(sizeof(char) * (len + 1));
	if (str == '\0')
		return (NULL);
	if (index < 0)
	{
		str[0] = '-';
		index = -index;
	}
	if (index == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (index != 0)
	{
		str[len] = index % 10 + '0';
		len--;
		index = index / 10;
	}
	return (str);
}

void	print_wall1(t_data *my)
{
	my->x = 0;
	my->y = 0;
	my->j = 0;
	my->f = 0;
	while (my->map[my->f])
	{
		while (my->map[my->f][my->j])
		{
			if (my->map[my->f][my->j] == '1')
				mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
					my->img_1, my->x, my->y);
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
}

void	print_0(t_data *my)
{
	my->i = 0;
	my->x = 0;
	my->y = 0;
	my->j = 0;
	my->f = 0;
	while (my->map[my->f])
	{
		while (my->map[my->f][my->j])
		{
			if (my->map[my->f][my->j] == '0' || my->map[my->f][my->j] == 'P'
			|| my->map[my->f][my->j] == 'E')
				mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
					my->img_0, my->x, my->y);
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
}
