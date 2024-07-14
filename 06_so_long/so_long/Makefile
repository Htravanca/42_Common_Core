# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 13:01:52 by hepereir          #+#    #+#              #
#    Updated: 2024/07/12 15:39:28 by hepereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

SRC = 
OBJ = $(SRC:.c=.o)

INCLUDES 			= -I/usr/include -Imlx
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS 		= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
 
clean:
	$(RM) $(OBJ)
 
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
