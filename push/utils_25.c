/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_25.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:43:40 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 01:43:41 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char	*p;

	p = str;
	while (len-- > 0)
	{
		*p = c;
		p++;
	}
	return (str);
}

long	long	ft_atoi(char *str, t_data *data)
{
	long long	sing;
	long long	ok;
	long long	i;

	ok = 0;
	i = 0;
	sing = 1;
	if (str[i] == '-')
		sing = -1;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '0'
			|| str[i + 1] == '1' || str[i + 1] == '2' || str[i + 1] == '3'
			|| str[i + 1] == '4' || str[i + 1] == '5' || str[i + 1] == '6'
			|| str[i + 1] == '7' || str[i + 1] == '8' || str[i + 1] == '9'))
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ok = (ok * 10) + str[i] - 48;
		else
			error_and_exit(data);
		i++;
	}
	check_max_min_atoi(ok, sing);
	return (ok * sing);
}
