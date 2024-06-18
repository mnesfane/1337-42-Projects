/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:41:00 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 21:43:20 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_free(t_data *ptr, int i)
{
	t_list	*tmp;

	if (ptr->stack_top_a->link)
	{
		while (ptr->stack_top_a)
		{
			tmp = ptr->stack_top_a;
			ptr->stack_top_a = ptr->stack_top_a->link;
			free(tmp);
		}
	}
	if (i == 1)
		write(2, "Error\n", 6);
	exit(0);
}

void	check_max_min_atoi(long long ok, long long sing)
{
	if ((ok * sing) > 2147483647 || (ok * sing) < -2147483648)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	error_and_exit(t_data *data)
{
	(void)data;
	write(2, "Error\n", 6);
	exit(0);
}
