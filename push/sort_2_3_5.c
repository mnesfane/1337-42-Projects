/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:42:36 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:42:38 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_a(t_data *ptr)
{
	t_list	*tmp;

	tmp = ptr->stack_top_a;
	ptr->maxa = ptr->stack_top_a;
	while (ptr->stack_top_a)
	{
		if (ptr->stack_top_a->data > ptr->maxa->data)
		{
			ptr->maxa = ptr->stack_top_a;
		}
		ptr->stack_top_a = ptr->stack_top_a->link;
	}
	ptr->stack_top_a = tmp;
	return (ptr->maxa->data);
}

int	min(t_data *ptr)
{
	t_list	*tmp;

	ptr->pointam = 0;
	tmp = ptr->stack_top_a;
	ptr->min = tmp;
	while (tmp)
	{
		if (ptr->min->data > tmp->data)
		{
			ptr->min = tmp;
		}
		tmp = tmp->link;
	}
	return (ptr->min->data);
}

int	sort_3(t_data *ptr)
{
	t_list	*tmp;

	if (sscheck_sort_stack(ptr) == 0)
		do_free(ptr, 0);
	tmp = ptr->stack_top_a;
	if (tmp->data == max_a(ptr))
	{
		if (ptr->stack_end_a->data == min(ptr))
			return (sa(ptr), rra(ptr), 0);
		else
			return (ra(ptr), 0);
	}
	if (tmp->link->data == max_a(ptr))
	{
		if (ptr->stack_end_a->data == min(ptr))
			return (rra(ptr), 0);
		else
			return (sa(ptr), ra(ptr), 0);
	}
	if (ptr->stack_end_a->data == max_a(ptr))
		return (sa(ptr), 0);
	return (0);
}

int	ssort_3(t_data *ptr)
{
	t_list	*tmp;

	if (sscheck_sort_stack(ptr) == 0)
		return (0);
	tmp = ptr->stack_top_a;
	if (tmp->data == max_a(ptr))
	{
		if (ptr->stack_end_a->data == min(ptr))
			return (sa(ptr), rra(ptr), 0);
		else
			return (ra(ptr), 0);
	}
	if (tmp->link->data == max_a(ptr))
	{
		if (ptr->stack_end_a->data == min(ptr))
			return (rra(ptr), 0);
		else
			return (sa(ptr), ra(ptr), 0);
	}
	if (ptr->stack_end_a->data == max_a(ptr))
		return (sa(ptr), 0);
	return (0);
}

void	sort_5(t_data *ptr)
{
	t_list	*tmp;

	if (sscheck_sort_stack(ptr) == 0)
		do_free(ptr, 0);
	tmp = ptr->stack_top_a;
	push_min(ptr);
	get_addr_end(ptr);
	push_min(ptr);
	get_addr_end(ptr);
	ssort_3(ptr);
	pa(ptr);
	pa(ptr);
	exit(0);
}
