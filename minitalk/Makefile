# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 16:34:11 by mnesfane          #+#    #+#              #
#    Updated: 2022/02/26 20:17:08 by mnesfane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = gcc

CLIENT = client.c
SERVER = server.c

CLIENTBONUS = clientbonus.c
SERVERBONUS = serverbonus.c

OBJC = $(CLIENT:.c=.o)
OBJS = $(SERVER:.c=.o)

OBJCBONUS = $(CLIENTBONUS:.c=.o)
OBJSBONUS = $(SERVERBONUS:.c=.o)

RM = rm -rf
NAME = minitalk
BNAME = minitalkbonus
INC = minitalk.h

all : $(NAME)

$(NAME): $(INC) $(OBJC) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS)  -o server
	@$(CC) $(CFLAGS) $(OBJC)  -o client

bonus : $(BNAME)
	
$(BNAME): $(INC) $(OBJSBONUS) $(OBJCBONUS)
	@$(CC) $(CFLAGS) $(OBJSBONUS)  -o serverbonus
	@$(CC) $(CFLAGS) $(OBJCBONUS)  -o clientbonus

clean :
	$(RM) $(OBJS) $(OBJC) $(OBJSBONUS) $(OBJCBONUS) server client serverbonus clientbonus
fclean : clean
		$(RM) $(NAME)
		$(RM) $(BNAME)

re : fclean all
reb : fclean bonus