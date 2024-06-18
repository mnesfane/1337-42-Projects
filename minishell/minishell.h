/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:01:21 by mnesfane          #+#    #+#             */
/*   Updated: 2022/07/24 00:17:45 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
#include <limits.h>


typedef struct s_struct
{
	int r;
	char **ss;
	char *oldpwd;
	int i;
	char *line;
	char **split;
	char *cwd;
	char **env;
}t_data;

void	data_init(t_data *data);
int		ft_strcmp(char *s1, char *s2, int n);
int	ft_strcmpenv(char *s1, char *s2, int n);
int		ft_strlen(char *str);
void    ft_echo(t_data *data);
char    **ft_split(char *s, char c);
void	ft_exit(void);
void	ft_pwd(void);
void	ft_cd(t_data *data);
char	*ft_strjoin(char *s1, char *s2);
void    ft_env(t_data *data);
// char	*env_pwd(t_data *data, int j);
void	ft_echo(t_data *data);
void	ft_unset(t_data *data);
void	ft_export(t_data *data);
int		ft_strstr(char *str, char *to_find);
int		ft_isalpha(int c);
void	split_env(t_data *data);
void	ft_putstr(char *str);
void	printadded_var(t_data *data, int i, char **ss);
int		char_compaire(char *str, char c);
#endif