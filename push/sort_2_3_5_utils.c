/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_5_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:42:28 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:42:30 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_max(t_data *ptr)
{
	t_list	*tmp;

	tmp = ptr->stack_top_a;
	max_a(ptr);
	maxposa(ptr);
	if (ptr->point <= 3)
	{	
		while (ptr->point)
		{
			ra(ptr);
			ptr->point--;
		}
	}
	else
	{
		ptr->point = 5 - ptr->point;
		while (ptr->point)
		{
			rra(ptr);
			ptr->point--;
		}
	}
	pb(ptr);
}

void	push_min(t_data *ptr)
{
	t_list	*tmp;

	tmp = ptr->stack_top_a;
	min(ptr);
	minposa(ptr);
	if (ptr->pointam <= 3)
	{
		while (ptr->pointam)
		{
			ra(ptr);
			ptr->pointam--;
		}
	}
	else
	{
		ptr->pointam = 5 - ptr->pointam;
		while (ptr->pointam)
		{
			rra(ptr);
			ptr->pointam--;
		}
	}
	pb(ptr);
}

int	maxposa(t_data *ptr)
{
	t_list	*tmp;

	tmp = ptr->stack_top_a;
	ptr->point = 0;
	while (tmp != ptr->maxa)
	{
		ptr->point++;
		tmp = tmp->link;
	}
	return (ptr->point);
}

int	minposa(t_data *ptr)
{
	t_list	*tmp;

	tmp = ptr->stack_top_a;
	ptr->pointam = 0;
	while (tmp != ptr->min)
	{
		ptr->pointam++;
		tmp = tmp->link;
	}
	return (ptr->pointam);
}
