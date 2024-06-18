# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 03:37:01 by mhanda            #+#    #+#              #
#    Updated: 2022/02/12 18:19:00 by mnesfane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC := cc
CFLAGS := -Wall -Werror -Wextra
LINKS := -lmlx -framework OpenGL -framework AppKit
PRINTF = ft_printf/libftprintf.a
CFILES := mandatory/so_long_u1.c \
						mandatory/so_long_u2.c \
						mandatory/so_long.c \
						mandatory/so_long2.c \
						mandatory/window.c \
						mandatory/window2.c \
						mandatory/window3.c
						
BCFILES := bonus/so_long_ub1.c \
						bonus/so_long_ub2.c \
						bonus/so_longb.c \
						bonus/so_longb2.c \
						bonus/windowb.c \
						bonus/windowb2.c \
						bonus/windowb3.c \
						bonus/windowb4.c \
						bonus/windowb5.c 
 
OFILES := $(CFILES:.c=.o)
BOFILES := $(BCFILES:.c=.o)


INC := mandatory/so_long.h
BINC := bonus/so_longbonus.h


NAME := so_long
BNAME := so_longbonus
	
	
$(NAME) : $(OFILES) $(INC) $(PRINTF)
	$(CC) $(CFLAGS) $(CFILES) $(PRINTF) $(LINKS) -o $(NAME)

$(BNAME) : $(BOFILES) $(BINC) $(PRINTF)
	$(CC) $(CFLAGS) $(BCFILES) $(PRINTF) $(LINKS) -o $(BNAME)
	
$(PRINTF):
	make -C ft_printf

all : $(NAME)

bonus : $(BNAME)
clean :
	@rm -rf $(OFILES)
	@rm -rf $(BOFILES)
	make -C ft_printf clean
fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(BNAME)
	make -C ft_printf fclean

re : fclean all
reb : fclean bonus