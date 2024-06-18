/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longbonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:42:36 by mnesfane          #+#    #+#             */
/*   Updated: 2022/02/12 18:13:17 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONGBONUS_H
# define SO_LONGBONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include "../ft_printf/ft_printf.h"

typedef struct var
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;
}t_game;

typedef struct s_data
{
	int		image_reminder;
	int		chang_image_2;
	int		chang_image_3;
	void	*img_1;
	void	*img_p_1;
	void	*img_p_2;
	void	*img_p_3;
	void	*img_f;
	void	*img_c;
	void	*img_e1;
	void	*img_e2;
	void	*img_0;
	char	*t;
	int		h;
	int		w;
	int		i;
	int		x;
	int		y;
	int		n;
	int		fd;
	int		j;
	int		f;
	int		rescoll;
	int		eatencoll;
	int		mouve_count;
	char	*addr;
	char	*path;
	void	*img;
	char	*line;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*imgb;
}t_data;

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *c);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *str);
char	**ft_split(char const *s, char c);
int		wdc(char const *s, char c);
char	*ft_strstr(const char *s, const char *tofind);
void	print_mape(t_data *my);
int		ft_mapelines(char **map);
int		ft_valid_map(int fd, int i);
void	*ft_memset(void *str, int c, size_t len);
char	**ft_split(char const *s, char c);
int		check_map(char **map, char *line);
int		lines(char *line);
int		checkext(char *av);
char	*read_map(int fd, char *line);
int		valid_map(int fd, int i);
int		check_map2(char *line, char **map);
void	print_wall1(t_data *my);
int		print_p(t_data *my);
void	print_c(t_data *my);
void	print_0(t_data *my);
void	print_f(t_data *my);
void	print_e1(t_data *my);
void	print_e2(t_data *my);
void	ft_collect_conter(t_data *my);
int		ft_locat_p(t_data *my);
int		ft_moveleft(t_data *my);
int		ft_moveright(t_data *my);
int		ft_movedown(t_data *my);
int		ft_move_up(t_data *my);
void	ft_print_img(t_data *my);
void	print_mape(t_data *my);
char	*ft_itoa(int n);
void	ft_keys(int k, t_data *my);
int		key(int k, t_data *my);
int		sa(t_data *my);
void	my_path(t_data *my);
void	fnorm(t_data *my);
int		free_all(t_data *my);
void	norm(t_data *my);
#endif
