# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 16:47:13 by hepereir          #+#    #+#              #
#    Updated: 2024/09/22 14:54:54 by hepereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
LIBFT			= libft/libft.a

SRC = pipex.c pipex_aux.c split_adapt.c split_adapt2.c
SRC_B = pipex_bonus.c pipex_aux.c split_adapt.c split_adapt2.c
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

%.o: %.c
		@${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

bonus:	fclean $(OBJ_B) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ_B) $(LIBFT) -o $(NAME)
		@echo "$(NAME) (bonus) created"

$(LIBFT):
	@make -s -C ./libft

$(NAME):	$(OBJ) $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ} $(LIBFT) -o $(NAME)
		@echo "$(NAME) created"

clean:
	@$(RM) $(OBJ) $(OBJ_B)
	@make clean -s -C ./libft
	@echo "$(NAME) cleaned"


fclean:			clean
					@$(RM) $(NAME)
					@make fclean -s -C ./libft

re: fclean all

.PHONY: all clean fclean re
