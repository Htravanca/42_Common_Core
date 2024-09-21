# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 16:47:13 by hepereir          #+#    #+#              #
#    Updated: 2024/09/19 18:26:42 by hepereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
NAME_B			= pipex
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

bonus: $(NAME_B)

$(LIBFT):
	@make -s -C ./libft

$(NAME):	$(OBJ) $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ} $(LIBFT) -o $(NAME)
		@echo "$(NAME) created"

$(NAME_B):	$(OBJ_B) $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ_B} $(LIBFT) -o $(NAME_B)
		@echo "$(NAME_B) created"

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_B)
	@make clean -s -C ./libft
	@echo "$(NAME) cleaned"


fclean:			clean
					@$(RM) $(NAME)
					@$(RM) $(NAME_B)
					@$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
