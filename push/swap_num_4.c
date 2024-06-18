/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_num_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:42:58 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:43:00 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cra(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	if (ptr->stack_top_a && ptr->stack_top_a->link)
	{
		temp = ptr->stack_top_a;
		ptr->stack_top_a = ptr->stack_top_a->link;
		temp2 = ptr->stack_top_a;
		while (ptr->stack_top_a->link)
			ptr->stack_top_a = ptr->stack_top_a->link;
		ptr->stack_top_a->link = temp;
		ptr->stack_top_a = temp2;
		temp->link = NULL;
	}
}

void	crb(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	if (ptr->stack_top_b && ptr->stack_top_b->link)
	{
		temp = ptr->stack_top_b;
		ptr->stack_top_b = ptr->stack_top_b->link;
		temp2 = ptr->stack_top_b;
		while (ptr->stack_top_b->link)
			ptr->stack_top_b = ptr->stack_top_b->link;
		ptr->stack_top_b->link = temp;
		ptr->stack_top_b = temp2;
		temp->link = NULL;
	}
}

void	crra(t_data *ptr)
{
	t_list	*temp;

	if (ptr->stack_top_a && ptr->stack_top_a->link)
	{
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
}

void	crrb(t_data *ptr)
{
	t_list	*temp;

	if (ptr->stack_top_b && ptr->stack_top_b->link)
	{
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
}
