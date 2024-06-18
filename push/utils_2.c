/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:43:20 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:43:21 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_intcmp(long long *s1, long long *s2)
{
	if (*s1 == *s2)
		return (0);
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*p;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

void	check_sort_stack(t_data *ptr)
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
	{
		do_free(ptr, 0);
		exit(0);
	}
}

int	scheck_sort_stack(t_data *ptr)
{
	t_list	*tmp;

	if (ptr->stack_top_a)
	{	
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
	}
	return (1);
}
