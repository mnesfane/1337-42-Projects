/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:41:28 by youssama          #+#    #+#             */
/*   Updated: 2022/07/29 18:37:01 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	del_env_elem(t_env *env, t_env_elem *elem)
{
	if (elem && elem->next)
		elem->next->prev = elem->prev;
	if (elem && elem->prev)
		elem->prev->next = elem->next;
	env->size--;
	free(elem->key);
	free(elem->value);
	free(elem);
	elem = NULL;
}

void	del_env(t_env *env)
{
	t_env_elem	*tmp;

	tmp = env->head;
	while (tmp)
	{
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = tmp->next;
	}
	free(env);
}

char	**convert_array(t_env *env)
{
	t_env_elem	*tmp;
	char		**arr;
	int			i;

	i = 0;
	tmp = env->head;
	arr = ft_calloc(env->size + 1, sizeof(char *));
	if (arr)
	{
		while (i < env->size)
		{
			arr[i] = ft_strdup(tmp->key);
			if (tmp->value)
			{
				arr[i] = ft_strjoin(arr[i], "=");
				arr[i] = ft_strjoin(arr[i], tmp->value);
			}
			tmp = tmp->next;
			i++;
		}
		arr[i] = NULL;
	}
	return (arr);
}

void	split_ev(t_env *env, t_sh *sh)
{
	t_env_elem	*tmp;
	// char		**arr;
	int			i;

	i = 0;
	tmp = env->head;
	sh->varname = ft_calloc(env->size + 1, sizeof(char *));
	sh->varvalue = ft_calloc(env->size + 1, sizeof(char *));
	if (sh->varname && sh->varvalue)
	{
		while (i < env->size)
		{
			sh->varname[i] = ft_strdup(tmp->key);
			if (tmp->value)
				sh->varvalue[i] = ft_strdup(tmp->value);
			tmp = tmp->next;
			i++;
		}
		sh->varname[i] = NULL;
		sh->varvalue[i] = NULL;
	}
}
