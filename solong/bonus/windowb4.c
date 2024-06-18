/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowb4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:46:53 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/13 14:12:19 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_longbonus.h"

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

void	print_f(t_data *my)
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
			if (my->map[my->f][my->j] == 'F')
				mlx_put_image_to_window(my->mlx_ptr, my->win_ptr,
					my->img_f, my->x, my->y);
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

int	free_all(t_data *my)
{
	free(my->line);
	free(my->map);
	mlx_destroy_image(my->mlx_ptr, my->img_1);
	mlx_destroy_image(my->mlx_ptr, my->img_0);
	mlx_destroy_image(my->mlx_ptr, my->img_p_1);
	mlx_destroy_image(my->mlx_ptr, my->img_p_2);
	mlx_destroy_image(my->mlx_ptr, my->img_p_3);
	mlx_destroy_image(my->mlx_ptr, my->img_e1);
	mlx_destroy_image(my->mlx_ptr, my->img_e2);
	mlx_destroy_image(my->mlx_ptr, my->img_c);
	mlx_destroy_image(my->mlx_ptr, my->img_f);
	return (0);
}

int	ft_locat_p(t_data *my)
{
	my->i = 0;
	my->j = 0;
	while (my->map[my->i])
	{
		while (my->map[my->i][my->j])
		{
			if (my->map[my->i][my->j] == 'P')
				return (0);
			my->j++;
		}
		my->j = 0;
		my->i++;
	}
	return (0);
}
