# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 01:41:36 by mnesfane          #+#    #+#              #
#    Updated: 2022/04/14 01:41:39 by mnesfane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFILES  = push_swap.c utils.c utils_1.c utils_2.c utils_3.c utils_4.c compair.c swap_num.c secend_swap_num.c swap_num_3.c sort_2_3_5.c sort_2_3_5_utils.c ft_free.c compair_2.c swap_num_2.c swap_num_4.c utils_25.c

BCFILES = checkerr.c utils.c utils_1.c utils_2.c utils_3.c compair.c secend_swap_num.c swap_num.c utils_4.c get_next_line.c get_next_line_utils.c swap_num_3.c ft_free.c compair_2.c swap_num_2.c swap_num_4.c utils_25.c

OCFILES = $(CFILES:.c=.o)
BOCFILES = $(BCFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
NAME = push_swap
BNAME = checker 
INC = push_swap.h
BINC = checker.h

all : $(NAME)
bonus : $(BNAME)
$(NAME) : $(INC) $(OCFILES)
	$(CC) $(CFLAGS) $(OCFILES) -o push_swap

$(BNAME) : $(BINC) $(BOCFILES)
	$(CC) $(CFLAGS) $(BOCFILES) -o checker

clean :
	$(RM) $(OCFILES)
	$(RM) $(BOCFILES)
fclean : clean
	$(RM) $(NAME)
	$(RM) $(BNAME)

re : fclean all
reb : fclean bonus
