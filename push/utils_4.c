/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:43:33 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:43:35 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sf_split(t_list *node, char **av, t_data *data)
{
	int		j;
	char	**split;

	j = 0;
	split = merge_and_do_space(av);
	while (split[j])
	{
		node->data = ft_atoi(split[j], data);
		node->link = NULL;
		j++;
		if (split[j])
		{
			node->link = malloc(sizeof(t_list));
			node = node->link;
		}
	}
	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}

void	continu_push_to_a(t_data *ptr)
{
	while (maxpos(ptr))
	{
		rrb(ptr);
		ptr->point--;
	}
	pa(ptr);
}

void	push_to_a(t_data *ptr)
{
	t_list	*tmp;

	tmp = ptr->stack_top_a;
	get_len(ptr);
	while (ptr->lenb != 0)
	{
		max(ptr);
		if (maxpos(ptr) <= get_len(ptr))
		{
			while (maxpos(ptr))
			{
				rb(ptr);
				ptr->point--;
			}
			pa(ptr);
		}
		else if (maxpos(ptr) > get_len(ptr))
		{
			continu_push_to_a(ptr);
		}
	}
}

int	sscheck_sort_stack(t_data *ptr)
{
	t_list	*tmp;

	ptr->lenb = 0;
	ptr->lena = 0;
	tmp = ptr->stack_top_a;
	while (tmp)
	{
		ptr->lena++;
		tmp = tmp->link;
	}
	tmp = ptr->stack_top_a;
	while (tmp->link)
	{
		if (tmp->data < tmp->link->data)
			ptr->lenb++;
		tmp = tmp->link;
	}
	if ((ptr->lena - 1) == ptr->lenb)
		return (0);
	return (1);
}
