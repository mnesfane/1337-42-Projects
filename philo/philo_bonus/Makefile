# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 14:52:28 by mnesfane          #+#    #+#              #
#    Updated: 2022/06/21 14:52:31 by mnesfane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES  = philo_bonus.c util_b_0.c kill_part.c
BCFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
NAME = philo_bonus
INC = philo_bonus.h

bonus : $(NAME)

$(NAME) : $(INC) $(BCFILES)
	$(CC) $(CFLAGS) $(BCFILES) -o philo_bonus

clean :
	$(RM) $(BCFILES)

fclean : clean
	$(RM) $(NAME)

reb : fclean bonus
