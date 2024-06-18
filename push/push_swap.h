/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:02:25 by mnesfane          #+#    #+#             */
/*   Updated: 2022/04/14 21:03:34 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define  BUFFER_SIZE 1

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	long long		data;
	struct s_list	*link;
}	t_list;

typedef struct s_var
{
	int	k;
	int	f;
	int	i;
	int	j;
	int	len;
	int	count;
}	t_var;

typedef struct s_jme3
{
	int		i;
	int		f;
	int		j;
	char	**split;
}	t_j;

typedef struct s_data
{
	int		log_len_a;
	t_list	*stack_top_b;
	t_list	*tmp_sort;
	t_list	*maxb;
	t_list	*maxa;
	t_list	*min;
	t_list	*nodes;	
	int		decide;
	int		decide2;
	int		pointam;
	int		point;
	int		lenb;
	int		lena;
	int		sacend_len_a;
	t_list	*stack_top_a;
	t_list	*stack_end_a;
}	t_data;

void		sort_4(t_data *ptr);
void		*ft_memset(void *str, int c, size_t len);
int			get_len(t_data *ptr);
void		error_and_exit(t_data *data);
void		check_max_min_atoi(long long ok, long long sing);
void		do_free(t_data *ptr, int i);
int			minposa(t_data *ptr);
int			sscheck_sort_stack(t_data *ptr);
void		get_addr_end(t_data *ptr);
void		decide_sort(t_data *ptr);
int			sort_3(t_data *ptr);
int			ssort_3(t_data *ptr);
void		sort_5(t_data *ptr);
int			maxposa(t_data *ptr);
int			max_a(t_data *ptr);
int			min(t_data *ptr);
void		push_min(t_data *ptr);
void		push_max(t_data *ptr);
void		sf_split(t_list *node, char **av, t_data *data);
char		*ft_strjoinn(char *buffers, char *buff);
char		*ft_strchr(char *s, int c);
int			scheck_sort_stack(t_data *ptr);
void		ssa(t_data *ptr);
void		ssb(t_data *ptr);
void		srrb(t_data *ptr);
void		srra(t_data *ptr);
int			ft_strncmp(char *s1, char *s2, size_t n);
void		check_sort_stack(t_data *ptr);
int			ft_strlen(char *c);
int			ft_intcmp(long long *s1, long long *s2);
char		*ft_strjoin(char *s1, char *s2);
int			emty_str(char *str);
void		check_double_arg(t_list *ptr, t_list *node, t_data *data);
void		f_split(t_list *node, char **av, t_data *data);
char		**merge_and_do_space(char **av);
char		*get_next_line(int fd);
void		cmp_A(t_data *ptr);
int			get_len_a(t_data *ptr);
void		full_pos(t_data *ptr);
int			maxpos(t_data *ptr);
void		push_to_a(t_data *ptr);
void		max(t_data *ptr);
void		sateff(t_data *ptr);
void		laod_stack_tmp(t_data *ptr);
void		compair(t_data *ptr);
void		double_mouve_ss_rr_rrr(t_data *ptr, int num);
void		sdouble_mouve_ss_rr_rrr(t_data *ptr, int num);
char		**ft_split(char const *s, char c);
long long	ft_atoi(char *s, t_data *data);
void		pb(t_data *ptr);
void		cpb(t_data *ptr);
void		pa(t_data *ptr);
void		cpa(t_data *ptr);
void		rra(t_data *ptr);
void		crra(t_data *ptr);
void		rrb(t_data *ptr);
void		crrb(t_data *ptr);
void		ra(t_data *ptr);
void		cra(t_data *ptr);
void		sra(t_data *ptr);
void		rb(t_data *ptr);
void		crb(t_data *ptr);
void		srb(t_data *ptr);
void		sa(t_data *ptr);
void		csa(t_data *ptr);
void		sb(t_data *ptr);
void		csb(t_data *ptr);
#endif
