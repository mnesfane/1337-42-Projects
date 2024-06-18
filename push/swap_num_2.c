/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_num_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:42:42 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:42:44 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sra(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	temp = ptr->stack_top_a;
	ptr->stack_top_a = ptr->stack_top_a->link;
	temp2 = ptr->stack_top_a;
	while (ptr->stack_top_a->link)
		ptr->stack_top_a = ptr->stack_top_a->link;
	ptr->stack_top_a->link = temp;
	ptr->stack_top_a = temp2;
	temp->link = NULL;
}

void	rb(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	temp = ptr->stack_top_b;
	ptr->stack_top_b = ptr->stack_top_b->link;
	temp2 = ptr->stack_top_b;
	while (ptr->stack_top_b->link)
		ptr->stack_top_b = ptr->stack_top_b->link;
	ptr->stack_top_b->link = temp;
	ptr->stack_top_b = temp2;
	temp->link = NULL;
	write(1, "rb\n", 3);
}

void	srb(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	temp = ptr->stack_top_b;
	ptr->stack_top_b = ptr->stack_top_b->link;
	temp2 = ptr->stack_top_b;
	while (ptr->stack_top_b->link)
		ptr->stack_top_b = ptr->stack_top_b->link;
	ptr->stack_top_b->link = temp;
	ptr->stack_top_b = temp2;
	temp->link = NULL;
}

void	rra(t_data *ptr)
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
	write(1, "rra\n", 4);
}

void	rrb(t_data *ptr)
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
	write(1, "rrb\n", 4);
}
