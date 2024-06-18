/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:42:09 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 21:43:29 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sdo_check_and_alloc(t_data data)
{
	t_list	*tmp;

	while (data.stack_top_a->link != NULL)
	{
		laod_stack_tmp(&data);
		while (data.tmp_sort)
		{
			tmp = data.tmp_sort;
			data.tmp_sort = data.tmp_sort->link;
			free(tmp);
		}
	}
	max(&data);
	maxpos(&data);
	push_to_a(&data);
}

void	get_addr_end(t_data *ptr)
{
	t_list	*tmp;

	tmp = ptr->stack_top_a;
	while (tmp->link)
		tmp = tmp->link;
	ptr->stack_end_a = tmp;
}

void	sort_4(t_data *ptr)
{
	t_list	*tmp;

	if (sscheck_sort_stack(ptr) == 0)
		do_free(ptr, 0);
	tmp = ptr->stack_top_a;
	push_min(ptr);
	get_addr_end(ptr);
	ssort_3(ptr);
	pa(ptr);
	exit(0);
}

void	decide_sort(t_data *ptr)
{
	if (get_len_a(ptr) == 2)
	{
		sa(ptr);
		do_free(ptr, 0);
	}
	else if (get_len_a(ptr) == 5)
		sort_5(ptr);
	else if (get_len_a(ptr) == 4)
		sort_4(ptr);
	else if (get_len_a(ptr) == 3)
	{
		sort_3(ptr);
		do_free(ptr, 0);
		exit(0);
	}
	else if (get_len_a(ptr) == 500)
	{
		ptr->decide = 10;
		ptr->decide2 = 4;
	}
	else
	{
		ptr->decide = 3;
		ptr->decide2 = 2;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*node;
	t_list	*ptr;

	if (ac <= 1)
		exit (0);
	data.stack_top_b = NULL;
	data.stack_top_a = NULL;
	node = malloc(sizeof(t_list));
	data.stack_top_a = node;
	ptr = node;
	f_split(node, av, &data);
	check_double_arg(ptr, node, &data);
	check_sort_stack(&data);
	get_addr_end(&data);
	decide_sort(&data);
	sdo_check_and_alloc(data);
	do_free(&data, 0);
	return (0);
}
