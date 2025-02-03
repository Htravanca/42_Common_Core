NAME = philo
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRC = philo.c init_data.c utils.c

OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(LIBFT):
	@echo "${YELLOW}Compiling libft...${RESET}"
	@make -s -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	@${CC} ${CFLAGS} ${OBJ} $(LIBFT) -o $(NAME)
	@echo "${GREEN}$(NAME) created successfully.${RESET}"

%.o: %.c
	@echo "${YELLOW}Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}Cleaning object files...${RESET}"
	@$(RM) $(OBJ)
	@make clean -s -C ./libft

fclean: clean
	@echo "${RED}Deleting executable and libraries...${RESET}"
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "${RED}$(NAME) deleted successfully.${RESET}"

re: fclean all

run: all
	@./$(NAME)

r:
	make re && clear && ./minishell

va: $(NAME)
	@valgrind --leak-check=full --track-fds=yes --show-leak-kinds=all ./$(NAME)

v: all
	@valgrind ./$(NAME)

.PHONY: all, clean, fclean, re, run, va, v