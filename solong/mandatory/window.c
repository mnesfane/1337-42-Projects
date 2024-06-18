/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:36:26 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/12 16:26:10 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	print_p(t_data *my)
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
			if (my->map[my->f][my->j] == 'P')
			{
				mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
					my->img_p, my->x, my->y);
			}
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
}

void	print_e(t_data *my)
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
			if (my->map[my->f][my->j] == 'E')
				mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
					my->img_e, my->x, my->y);
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
}

void	print_c(t_data *my)
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
			if (my->map[my->f][my->j] == 'C')
				mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
					my->img_c, my->x, my->y);
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
}

void	ft_collect_conter(t_data *my)
{
	my->i = 0;
	my->j = 0;
	while (my->map[my->i])
	{
		while (my->map[my->i][my->j])
		{
			if (my->map[my->i][my->j] == 'C')
				my->rescoll++;
			my->j++;
		}
		my->j = 0;
		my->i++;
	}
}
