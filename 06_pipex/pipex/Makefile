# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 16:47:13 by hepereir          #+#    #+#              #
#    Updated: 2024/10/17 14:24:27 by hepereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
LIBFT			= libft/libft.a

SRC				= pipex.c pipex_aux.c pipex_aux2.c split_adapt.c split_adapt2.c
OBJ				= $(SRC:.c=.o)
SRC_B			= pipex_bonus.c pipex_aux_bonus.c pipex_aux2_bonus.c split_adapt_bonus.c split_adapt2_bonus.c
OBJ_B			= $(SRC_B:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

%.o: %.c
		@${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

bonus: $(OBJ_B) $(LIBFT)
		@${CC} ${CFLAGS} $(OBJ_B) $(LIBFT) -o $(NAME)
		@echo "$(NAME) (bonus) created"

$(LIBFT):
	@make -s -C ./libft

$(NAME): $(OBJ) $(LIBFT)
		@${CC} ${CFLAGS} $(OBJ) $(LIBFT) -o $(NAME)
		@echo "$(NAME) created"

clean:
	@$(RM) $(OBJ) $(OBJ_B)
	@make clean -s -C ./libft
	@echo "Object files cleaned"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C ./libft
	@echo "Executable cleaned"

re: fclean all

.PHONY: all clean fclean re bonus