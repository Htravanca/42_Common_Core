NAME = cub3d
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iinc

LIBFT = aux/libft/libft.a
GNL = aux/get_next_line/get_next_line.c aux/get_next_line/get_next_line_utils.c

MLX = mlx_linux/libmlx_Linux.a 
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

PR = src/parsing/
SRCS = src/
GAME = src/game/

GAME_SRC = $(GAME)handle_game.c $(GAME)raycasting.c $(GAME)raycasting_aux.c $(GAME)draw.c $(GAME)draw2.c $(GAME)movements.c $(GAME)exit.c

SRC = $(GNL) $(SRCS)main.c $(PR)parse.c $(PR)aux.c $(PR)name.c $(PR)textures.c $(PR)colors.c $(PR)map_size.c $(PR)map.c $(PR)map2.c $(PR)map3.c $(GAME_SRC)

OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(LIBFT):
	@echo "${YELLOW}Compiling libft...${RESET}"
	@make -s -C ./aux/libft

$(MLX):
	@echo "${YELLOW}Compiling MLX...${RESET}"
	@make -s -C mlx_linux

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "${YELLOW}Linking object files and libraries...${RESET}"
	@${CC} ${CFLAGS} ${OBJ} $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)
	@echo "${GREEN}$(NAME) created successfully.${RESET}"

%.o: %.c
	@echo "${YELLOW}Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}Cleaning object files...${RESET}"
	@$(RM) $(OBJ)
	@make clean -s -C ./aux/libft
	@make clean -s -C mlx_linux

fclean: clean
	@echo "${RED}Deleting executable and libraries...${RESET}"
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "${RED}$(NAME) deleted successfully.${RESET}"

re: fclean all

run: all
	@./$(NAME)

r:
	make re; make clean; clear

v:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)

.PHONY: all, clean, fclean, re, run, v