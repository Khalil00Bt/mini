# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khboutah <khboutah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 18:04:59 by khboutah          #+#    #+#              #
#    Updated: 2023/03/17 21:32:39 by khboutah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SRVR = server
NAME_CLIENT = client

SRVR_B = server_bonus
CLIENT_B = client_bonus

CC = cc

RM	= rm -rf

CFLAGS = -Wall -Werror -Wextra

all	: $(NAME_CLIENT) $(NAME_SRVR)

$(NAME_CLIENT) : client.c minitalk.h outils.c
		$(CC) $(CFLAGS) client.c outils.c -o client

$(NAME_SRVR) : server.c minitalk.h outils.c
		$(CC) $(CFLAGS) server.c outils.c -o server

bonus	: $(CLIENT_B) $(SRVR_B)

$(CLIENT_B)	: client_bonus.c minitalk.h outils.c
		$(CC) $(CFLAGS) client_bonus.c outils.c -o client_bonus

$(SRVR_B)	: server_bonus.c minitalk.h outils.c
		$(CC) $(CFLAGS) server_bonus.c outils.c -o server_bonus
clean	:
		$(RM) $(NAME_CLIENT) $(NAME_SRVR) $(CLIENT_B) $(SRVR_B)

fclean	:
		$(RM) $(NAME_CLIENT) $(NAME_SRVR) $(CLIENT_B) $(SRVR_B)
re	:    fclean all