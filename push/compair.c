/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compair.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:40:48 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 21:50:13 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_len(t_data *ptr)
{	
	t_var	var;
	t_list	*tmp;

	var.len = 0;
	tmp = ptr->stack_top_b;
	while (tmp->link)
	{
		var.len++;
		tmp = tmp->link;
	}
	ptr->lenb = var.len;
	var.len = var.len / 2;
	return (var.len);
}

int	maxpos(t_data *ptr)
{
	t_list	*tmp;

	tmp = ptr->stack_top_b;
	ptr->point = 0 ;
	while (tmp != ptr->maxb)
	{
		ptr->point++;
		tmp = tmp->link;
	}
	return (ptr->point);
}

void	max(t_data *ptr)
{
	t_list	*tmp;

	tmp = ptr->stack_top_b;
	ptr->maxb = ptr->stack_top_b;
	while (ptr->stack_top_b)
	{
		if (ptr->stack_top_b->data > ptr->maxb->data)
		{
			ptr->maxb = ptr->stack_top_b;
		}
		ptr->stack_top_b = ptr->stack_top_b->link;
	}
	ptr->stack_top_b = tmp;
}

void	laod_stack_tmp(t_data *ptr)
{
	t_list	*str;
	t_list	*tmp2;

	str = malloc(sizeof(t_list));
	str->link = NULL;
	ptr->tmp_sort = str;
	tmp2 = ptr->stack_top_a;
	while (ptr->stack_top_a)
	{
		str->data = ptr->stack_top_a->data;
		str->link = NULL;
		if (ptr->stack_top_a->link)
		{
			str->link = malloc(sizeof(t_list));
			str = str->link;
		}
		ptr->stack_top_a = ptr->stack_top_a->link;
	}
	ptr->stack_top_a = tmp2;
	sateff (ptr);
}

int	get_len_a(t_data *ptr)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = ptr->stack_top_a;
	while (tmp)
	{
		i++;
		tmp = tmp->link;
	}
	return (i);
}
