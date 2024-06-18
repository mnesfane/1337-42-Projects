/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secend_swap_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:42:22 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:42:24 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ssa(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = ptr->stack_top_a->link->link;
	temp = ptr->stack_top_a;
	ptr->stack_top_a = ptr->stack_top_a->link;
	ptr->stack_top_a->link = temp;
	ptr->stack_top_a->link->link = temp2;
}

void	ssb(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = ptr->stack_top_b->link->link;
	temp = ptr->stack_top_b;
	ptr->stack_top_b = ptr->stack_top_b->link;
	ptr->stack_top_b->link = temp;
	ptr->stack_top_b->link->link = temp2;
}

void	srrb(t_data *ptr)
{
	t_list	*temp;

	temp = ptr->stack_top_b;
	if (temp->link)
	{
		while (temp->link->link)
			temp = temp->link;
		temp->link->link = ptr->stack_top_b;
		ptr->stack_top_b = temp->link;
		temp->link = NULL;
	}
}

void	srra(t_data *ptr)
{
	t_list	*temp;

	temp = ptr->stack_top_a;
	if (temp->link)
	{
		while (temp->link->link)
			temp = temp->link;
		temp->link->link = ptr->stack_top_a;
		ptr->stack_top_a = temp->link;
		temp->link = NULL;
	}
}
