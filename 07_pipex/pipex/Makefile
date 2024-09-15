# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 16:47:13 by hepereir          #+#    #+#              #
#    Updated: 2024/09/15 16:48:43 by hepereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
LIBFT			= libft/libft.a

SRC = pipex.c pipex_aux.c
OBJ = $(SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	@make -s -C ./libft

$(NAME):	$(OBJ) $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ} $(LIBFT) -o $(NAME)
		@echo "$(NAME) created"

clean:
	@$(RM) $(OBJ)
	@make clean -s -C ./libft


fclean:			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
