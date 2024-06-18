/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:43:13 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:43:15 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double_arg(t_list *ptr, t_list *node, t_data *data)
{
	t_list	*tmp;

	tmp = node;
	while (ptr != NULL)
	{
		while (node->link != NULL)
		{
			if (ft_intcmp(&ptr->data, &node->link->data) == 0)
			{
				do_free(data, 1);
				exit(0);
			}
			node = node->link;
		}
		ptr = ptr->link;
		node = ptr;
	}
	node = tmp;
}

void	f_split(t_list *node, char **av, t_data *data)
{
	t_list	*ptr;
	int		j;
	char	**split;

	j = 0;
	ptr = node;
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
	node = ptr;
	data->nodes = node;
	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}

char	**merge_and_do_space(char **av)
{
	t_j		pop;
	char	*g;
	char	*str;
	char	**split;

	pop.i = 1;
	pop.f = 0;
	str = malloc(1);
	str[0] = '\0';
	while (av[pop.i])
	{
		if (emty_str(av[pop.i]) == 0)
		{
			free(str);
			exit (0);
		}
		g = ft_strjoin(str, av[pop.i]);
		free(str);
		str = ft_strjoin(g, " ");
		free(g);
		pop.i++;
	}
	split = ft_split(str, ' ');
	free(str);
	return (split);
}

int	emty_str(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			k++;
		i++;
	}
	if (k == i)
		return (write(2, "Error\n", 6), 0);
	else
		return (1);
}
