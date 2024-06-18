/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compair_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:02:52 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 21:01:57 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	continu_cmp(t_list *goldnum, t_list *g, t_data *ptr)
{
	if (ptr->stack_top_b->link)
	{
		if (ptr->stack_top_b->data < g->data)
		{
			if (ptr->stack_top_a->data > goldnum->data)
				double_mouve_ss_rr_rrr(ptr, 1);
			else
				rb(ptr);
		}
	}
}

void	cmp(t_list *goldnum, t_list *g, t_data *ptr)
{
	t_list	*tmp;
	t_var	var;

	tmp = ptr->stack_top_a;
	while (tmp)
	{
		if (tmp->data > goldnum->data)
			var.f++;
		if (tmp->data <= goldnum->data)
		{
			while (var.f)
			{
				ra(ptr);
				var.f--;
			}
			pb(ptr);
			tmp = ptr->stack_top_a;
			continu_cmp(goldnum, g, ptr);
		}
		else
			tmp = tmp->link;
	}
}

void	continu_compair(t_data *ptr, t_var *var, t_list *tmp)
{
	while (ptr->tmp_sort)
	{
		var->len++;
		ptr->tmp_sort = ptr->tmp_sort->link;
	}
	ptr->tmp_sort = tmp;
	var->len = var->len / ptr->decide;
	var->i = var->len / ptr->decide2;
}

void	compair(t_data *ptr)
{
	t_var	var;
	t_list	*goldnum;
	t_list	*tmp;
	t_list	*g;

	tmp = ptr->tmp_sort;
	var.len = 0;
	continu_compair(ptr, &var, tmp);
	while (var.len)
	{
		ptr->tmp_sort = ptr->tmp_sort->link;
		var.len--;
	}
	goldnum = ptr->tmp_sort;
	ptr->tmp_sort = tmp;
	while (var.i)
	{
		ptr->tmp_sort = ptr->tmp_sort->link;
		var.i--;
	}
	g = ptr->tmp_sort;
	ptr->tmp_sort = tmp;
	cmp(goldnum, g, ptr);
}
