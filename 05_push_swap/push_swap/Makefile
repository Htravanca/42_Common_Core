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

NAME			= push_swap

SRC = clean.c cost.c ft_split.c lst.c ops_p.c ops_rr.c ops_rrr.c ops_ss.c \
		parsing.c push_swap.c sort.c sort_aux.c sort_three.c
OBJ = $(SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
 
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
 
clean:
	$(RM) $(OBJ)
 
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
