# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 16:47:13 by hepereir          #+#    #+#              #
#    Updated: 2024/09/15 22:00:29 by hepereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
LIBFT			= libft/libft.a

SRC = pipex.c pipex_aux.c
OBJ = $(SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

%.o: %.c
		@${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(LIBFT):
	@make -s -C ./libft

$(NAME):	$(OBJ) $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ} $(LIBFT) -o $(NAME)
		@echo "$(NAME) created"

clean:
	@$(RM) $(OBJ)
	@make clean -s -C ./libft
	@echo "$(NAME) cleaned"


fclean:			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
