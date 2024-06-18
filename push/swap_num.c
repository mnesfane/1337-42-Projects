/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:43:05 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:43:07 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_data *ptr)
{
	t_list		*temp;
	static int	remind;

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
	write(1, "pb\n", 3);
}

void	pa(t_data *ptr)
{
	t_list	*temp;

	if (ptr->stack_top_b != NULL)
	{	
		temp = ptr->stack_top_a;
		ptr->stack_top_a = ptr->stack_top_b;
		ptr->stack_top_b = ptr->stack_top_b->link;
		ptr->stack_top_a->link = temp;
	}
	write(1, "pa\n", 3);
}

void	sa(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = ptr->stack_top_a->link->link;
	temp = ptr->stack_top_a;
	ptr->stack_top_a = ptr->stack_top_a->link;
	ptr->stack_top_a->link = temp;
	ptr->stack_top_a->link->link = temp2;
	write(1, "sa\n", 3);
}

void	sb(t_data *ptr)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = ptr->stack_top_b->link->link;
	temp = ptr->stack_top_b;
	ptr->stack_top_b = ptr->stack_top_b->link;
	ptr->stack_top_b->link = temp;
	ptr->stack_top_b->link->link = temp2;
	write(1, "sb\n", 3);
}

void	ra(t_data *ptr)
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
	write(1, "ra\n", 3);
}
