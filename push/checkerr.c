/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:02:43 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 00:02:46 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	instructions_and_execute(char *str, t_data *t)
{
	if (!ft_strncmp(str, "sa\n", 3))
		csa(t);
	else if (!ft_strncmp(str, "sb\n", 3))
		csb(t);
	else if (!ft_strncmp(str, "ss\n", 3))
		sdouble_mouve_ss_rr_rrr(t, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		cpa(t);
	else if (!ft_strncmp(str, "pb\n", 3))
		cpb(t);
	else if (!ft_strncmp(str, "ra\n", 3))
		cra(t);
	else if (!ft_strncmp(str, "rb\n", 3))
		crb(t);
	else if (!ft_strncmp(str, "rr\n", 3))
		sdouble_mouve_ss_rr_rrr(t, 1);
	else if (!ft_strncmp(str, "rra\n", 4))
		crra(t);
	else if (!ft_strncmp(str, "rrb\n", 4))
		crrb(t);
	else if (!ft_strncmp(str, "rrr\n", 4))
		sdouble_mouve_ss_rr_rrr(t, 2);
	else
		write(2, "Error\n", 6);
}

void	check_ok_ko(t_data *ptr)
{
	if ((scheck_sort_stack(ptr) == 0) && !ptr->stack_top_b)
	{
		write(1, "OK\n", 3);
		do_free(ptr, 0);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 3);
		do_free(ptr, 0);
		exit(0);
	}
}

void	do_check_and_alloc(t_data *data, char **av)
{
	t_list	*node;
	t_list	*ptr;

	node = malloc(sizeof(t_list));
	data->stack_top_a = node;
	ptr = node;
	sf_split(node, av, data);
	node = ptr;
	check_double_arg(ptr, node, data);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	*str;

	if (ac <= 1)
		exit(0);
	data.stack_top_b = NULL;
	data.stack_top_a = NULL;
	do_check_and_alloc(&data, av);
	str = get_next_line(0);
	while (str)
	{
		instructions_and_execute(str, &data);
		free(str);
		str = get_next_line(0);
	}
	check_ok_ko(&data);
}
