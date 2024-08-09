# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 13:01:52 by hepereir          #+#    #+#              #
#    Updated: 2024/08/09 17:29:57 by hepereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
PRINTF			= ft_printf/libftprintf.a
LIBFT			= libft/libft.a
MLX				= minilibx-linux/libmlx.a

SRC = so_long.c game.c game2.c map_checker.c map_checker2.c parsing.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
OBJ = $(SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS 		= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

all: $(NAME)

$(PRINTF):
	@make -s -C ./ft_printf

$(MLX):
	@make -s -C ./minilibx-linux

$(LIBFT):
	@make -s -C ./libft

$(NAME):	$(OBJ) $(LIBFT) $(PRINTF) $(MLX)
		@${CC} ${CFLAGS} $(MLX_FLAGS) ${OBJ} $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)
		@echo "$(NAME) created"

clean:
	@$(RM) $(OBJ)
	@make clean -s -C ./ft_printf
	@make clean -s -C ./minilibx-linux
	@make clean -s -C ./libft


fclean:			clean
					@$(RM) $(NAME)
					@$(RM) $(PRINTF)
					@$(RM) $(MLX)
					@$(RM) $(LIBFT)
					@echo "$(NAME) deleted"

re: fclean all

.PHONY: fclean all
