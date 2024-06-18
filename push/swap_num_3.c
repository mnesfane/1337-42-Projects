/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_num_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:42:50 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:42:52 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cpb(t_data *ptr)
{
	t_list		*temp;
	static int	remind;

	if (ptr->stack_top_a)
	{
		if (ptr->stack_top_a != NULL)
		{
			if (remind == 0)
			{
				ptr->stack_top_b = ptr->stack_top_a;
				ptr->stack_top_a = ptr->stack_top_a->link;
				ptr->stack_top_b->link = NULL;
				remind ++;
			}
			else
			{
				temp = ptr->stack_top_b;
				ptr->stack_top_b = ptr->stack_top_a;
				ptr->stack_top_a = ptr->stack_top_a->link;
				ptr->stack_top_b->link = temp;
			}
		}
	}
}

void	cpa(t_data *ptr)
{
	t_list	*temp;

	if (ptr->stack_top_b)
	{
		if (ptr->stack_top_b != NULL)
		{	
			temp = ptr->stack_top_a;
			ptr->stack_top_a = ptr->stack_top_b;
			ptr->stack_top_b = ptr->stack_top_b->link;
			ptr->stack_top_a->link = temp;
		}
	}
}

void	csa(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	if (ptr->stack_top_a && ptr->stack_top_a->link)
	{
		temp2 = ptr->stack_top_a->link->link;
		temp = ptr->stack_top_a;
		ptr->stack_top_a = ptr->stack_top_a->link;
		ptr->stack_top_a->link = temp;
		ptr->stack_top_a->link->link = temp2;
	}
}

void	csb(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	if (ptr->stack_top_b && ptr->stack_top_b->link)
	{
		temp2 = ptr->stack_top_b->link->link;
		temp = ptr->stack_top_b;
		ptr->stack_top_b = ptr->stack_top_b->link;
		ptr->stack_top_b->link = temp;
		ptr->stack_top_b->link->link = temp2;
	}
}
