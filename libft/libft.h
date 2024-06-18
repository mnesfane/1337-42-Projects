/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:05:02 by mnesfane          #+#    #+#             */
/*   Updated: 2021/11/23 17:42:47 by mnesfane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_isdigit(int c);
int		ft_toupper(int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s, const char *tofind, size_t len);
int		ft_strncmp(const char *c, const char *s, size_t n);
size_t	ft_strlen(const char *c);
size_t	ft_strlcpy(char *s1, const char *s2, size_t t);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *str, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *str1, const void *str2, size_t len);
void	*ft_memchr(const void *str, int c, size_t len);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	*ft_calloc(size_t nitems, size_t sizeitems);
void	*ft_bzero(void *str, size_t len);
int		ft_atoi(const char *s);
int		ft_tolower(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif
