/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:34:03 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/12 00:35:21 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_moveleft(t_data *my)
{
	ft_locat_p(my);
	if (my->map[my->i][my->j - 1] == '1')
		return (0);
	if (my->map[my->i][my->j - 1] == '0')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i][my->j - 1] = 'P';
		my->mouve_count++;
	}
	if (my->map[my->i][my->j - 1] == 'C')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i][my->j - 1] = 'P';
		my->eatencoll++;
		my->mouve_count++;
	}
	if (my->map[my->i][my->j - 1] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("%s", "You win !\n");
		exit (0);
	}
	return (0);
}

int	ft_moveright(t_data *my)
{
	ft_locat_p(my);
	if (my->map[my->i][my->j + 1] == '1')
		return (0);
	if (my->map[my->i][my->j + 1] == '0')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i][my->j + 1] = 'P';
		my->mouve_count++;
	}
	if (my->map[my->i][my->j + 1] == 'C')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i][my->j + 1] = 'P';
		my->eatencoll++;
		my->mouve_count++;
	}
	if (my->map[my->i][my->j + 1] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("%s", "You win !\n");
		exit (0);
	}
	return (0);
}

int	ft_movedown(t_data *my)
{
	ft_locat_p(my);
	if (my->map[my->i + 1][my->j] == '1')
		return (0);
	if (my->map[my->i + 1][my->j] == '0')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i + 1][my->j] = 'P';
		my->mouve_count++;
	}
	if (my->map[my->i + 1][my->j] == 'C')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i + 1][my->j] = 'P';
		my->eatencoll++;
		my->mouve_count++;
	}
	if (my->map[my->i + 1][my->j] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("%s", "You win !\n");
		exit (0);
	}
	return (0);
}

int	ft_move_up(t_data *my)
{
	ft_locat_p(my);
	if (my->map[my->i - 1][my->j] == '1')
		return (0);
	if (my->map[my->i - 1][my->j] == '0')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i - 1][my->j] = 'P';
		my->mouve_count++;
	}
	if (my->map[my->i - 1][my->j] == 'C')
	{
		my->map[my->i][my->j] = '0';
		my->map[my->i - 1][my->j] = 'P';
		my->eatencoll++;
		my->mouve_count++;
	}
	if (my->map[my->i - 1][my->j] == 'E' && my->rescoll == my->eatencoll)
	{
		ft_printf("%s", "You win !\n");
		exit (0);
	}
	return (0);
}
