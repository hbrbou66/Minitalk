# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbou-dou <hbou-dou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 11:37:21 by moaziz            #+#    #+#              #
#    Updated: 2025/02/14 13:06:06 by hbou-dou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCC = client.c utils.c
SRCS = server.c utils.c

OBJC = $(SRCC:.c=.o)
OBJS = $(SRCS:.c=.o)

CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJC)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(OBJC)

$(SERVER): $(OBJS)
	@$(CC) $(CFLAGS) -o $(SERVER) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJC) $(OBJS)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)

re: fclean all
