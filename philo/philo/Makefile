# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 12:40:16 by mnesfane          #+#    #+#              #
#    Updated: 2022/06/21 12:40:19 by mnesfane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES  = main.c util_0.c util_1.c
OCFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
NAME = philo
INC = philo.h

all : $(NAME)

$(NAME) : $(INC) $(OCFILES)
	$(CC) $(CFLAGS) $(OCFILES) -o philo

clean :
	$(RM) $(OCFILES)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all
reb : fclean bonus
