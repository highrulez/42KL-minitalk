# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 19:27:33 by aawgku-o          #+#    #+#              #
#    Updated: 2023/12/10 03:00:30 by aawgku-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER 			= server
CLIENT			= client

SERVERSRC 		= server.c
CLIENTSRC 		= client.c

OBJCLIENT		= $(CLIENTSRC:.c=.o)
OBJSERVER		= $(SERVERSRC:.c=.o)

CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra
LIBPRTF 		= ./ft_printf/libftprintf.a
PRTFSRC			= ./ft_printf/

RM				= rm -f

all: 		  	$(SERVER) $(CLIENT)

$(SERVER): 	  	$(OBJSERVER)
			  	@make -s -C $(PRTFSRC)
			  	@$(CC) -o $(SERVER) $(SERVERSRC) $(LIBPRTF)

$(CLIENT): 	  	$(OBJCLIENT)
			  	@make -s -C $(PRTFSRC)
			  	@$(CC) -o $(CLIENT) $(CLIENTSRC) $(LIBPRTF)

clean:		  
			  	@$(RM) $(OBJSERVER) $(OBJCLIENT)
			  	@cd $(PRTFSRC) && make clean
	
fclean: 	  	clean
			  	@$(RM) $(SERVER) $(CLIENT)
			  	@cd $(PRTFSRC) && make fclean
	
re: 		  	fclean all

.PHONY: 		all fclean re bonus
