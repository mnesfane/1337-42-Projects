# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnesfane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 20:37:52 by mnesfane          #+#    #+#              #
#    Updated: 2021/11/23 17:38:56 by mnesfane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_isascii.c \
		  	ft_memmove.c \
			ft_strlcpy.c \
			ft_atoi.c \
			ft_isprint.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_substr.c \
			ft_bzero.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_strdup.c \
			ft_strmapi.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_memchr.c \
			ft_strncmp.c \
			ft_toupper.c \
			ft_isalnum.c \
			ft_memcmp.c \
			ft_strjoin.c \
			ft_strnstr.c \
			ft_isalpha.c \
			ft_memcpy.c \
			ft_strlcat.c \
			ft_isdigit.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strtrim.c \
			ft_split.c \
			ft_strrchr.c \
			ft_striteri.c

INCLUDE = libft.h
OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) $(INCLUDE)
		ar rcs $(NAME) $(OBJECTS)

clean :
		rm -rf $(OBJECTS)

fclean : clean
		rm -f $(NAME)

re : fclean all
