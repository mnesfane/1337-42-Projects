# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 15:19:35 by mnesfane          #+#    #+#              #
#    Updated: 2022/02/08 20:57:36 by mnesfane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_putchar.c \
			ft_puthexa.c \
			ft_putnbr.c \
			ft_putnbru.c \
			ft_putprt.c \
			ft_putstr.c \
			ft_printf.c
			
INCLUDE = ft_printf.h

OBJECTS =$(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) $(INCLUDE)
		ar rcs $(NAME) $(OBJECTS)
	
clean :
		rm -rf $(OBJECTS)

fclean : clean
		rm -f $(NAME)

re : fclean all
			