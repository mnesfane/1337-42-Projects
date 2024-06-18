/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:43:27 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:43:29 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	double_mouve_ss_rr_rrr(t_data *ptr, int num)
{
	if (num == 0)
	{
		ssa(ptr);
		ssb(ptr);
		write(1, "ss\n", 3);
	}
	if (num == 1)
	{
		srb(ptr);
		sra(ptr);
		write(1, "rr\n", 3);
	}
	if (num == 2)
	{
		srra(ptr);
		srrb(ptr);
		write(1, "rrr\n", 4);
	}
}

void	sdouble_mouve_ss_rr_rrr(t_data *ptr, int num)
{
	if (num == 0)
	{
		csa(ptr);
		csb(ptr);
	}
	if (num == 1)
	{
		crb(ptr);
		cra(ptr);
	}
	if (num == 2)
	{
		crra(ptr);
		crrb(ptr);
	}
}

void	continu_sateff(t_data *ptr, t_var *var, t_list *tmp1)
{
	while (var->len)
	{
		ptr->tmp_sort = tmp1;
		while (ptr->tmp_sort->link)
		{
			if (ptr->tmp_sort->data > ptr->tmp_sort->link->data)
			{
				var->count = ptr->tmp_sort->data;
				ptr->tmp_sort->data = ptr->tmp_sort->link->data;
				ptr->tmp_sort->link->data = var->count;
			}
			ptr->tmp_sort = ptr->tmp_sort->link;
		}
		var->len--;
	}
}

void	sateff(t_data *ptr)
{
	t_var	var;
	t_list	*tmp1;

	var.i = 0;
	var.len = 0;
	var.j = 0;
	var.count = 0;
	tmp1 = ptr->tmp_sort;
	while (ptr->tmp_sort)
	{
		ptr->tmp_sort = ptr->tmp_sort->link;
		var.len++;
	}
	var.count = 0;
	continu_sateff(ptr, &var, tmp1);
	ptr->tmp_sort = tmp1;
	compair(ptr);
}
