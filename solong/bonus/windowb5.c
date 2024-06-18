/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowb5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:47:44 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/12 18:06:13 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_longbonus.h"

void	norm(t_data *my)
{
	mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
		my->img_0, my->x, my->y);
	if (my->image_reminder <= 5)
	{
		mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
			my->img_p_1, my->x, my->y);
	}
	if (my->image_reminder >= 6 && my->image_reminder <= 10)
	{
		mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
			my->img_p_2, my->x, my->y);
	}
	if (my->image_reminder >= 11)
	{
		mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
			my->img_p_3, my->x, my->y);
	}
	my->image_reminder++;
	if (my->image_reminder == 15)
					my->image_reminder = 0;
}

int	print_p(t_data *my)
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
				norm(my);
			}
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
	return (0);
}

void	print_e1(t_data *my)
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
					my->img_e1, my->x, my->y);
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
}

void	print_e2(t_data *my)
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
					my->img_e2, my->x, my->y);
			my->x += 64;
			my->j++;
		}
		my->y += 64;
		my->x = 0;
		my->j = 0;
		my->f++;
	}
}
