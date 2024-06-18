/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:32:37 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 16:24:36 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_plus(int *i, int plus)
{
	if (!plus)
		(*i)++;
	else
		(*i) += plus;
}

void	check_cmd_state(t_elem**ptr, char **env, int *value)
{
	if ((*ptr)->state == GENERAL)
	{
		(*value)++;
		if ((*ptr)->type == ENV)
		{
			if (ft_strcmp(expand_env((*ptr)->content, env), "") == EQUAL)
				(*value)--;
		}
	}
	else
	{
		while ((*ptr) && (*ptr)->state != GENERAL)
			(*ptr) = (*ptr)->next;
		(*value)++;
	}
}
