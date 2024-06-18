# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 12:06:40 by mnesfane          #+#    #+#              #
#    Updated: 2022/07/24 00:00:56 by mnesfane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INC = minishell.h 

SRC = minishell.c bultins.c mini_utils1.c ft_cd.c mini_utils2.c ft_env_unset.c

#LIBINC = libft/libft.h

#LIBFT = libft/libft.a

INCLUDE_READLINE =  $(READLINE)/include

LIB_READLINE = $(READLINE)/lib

READLINE = $(shell brew --prefix readline)

CC = cc       
# -Wall -Wextra -Werror  


OBJ = $(SRC:.c=.o)

%.o : %.c $(INC)
	$(CC) -I $(INCLUDE_READLINE) -c $< -o $@

all : $(NAME)

$(NAME) : $(INC) $(OBJ)
	$(CC) $(OBJ) -I $(INCLUDE_READLINE)  -L $(LIB_READLINE)  -o $(NAME) -lreadline 

#$(LIBFT)	:
#make bonus -C libft

clean :
	rm -rf $(OBJ)
# make clean -C libft

fclean : clean
	rm -rf $(NAME)
#	make fclean -C libft

re : fclean all
