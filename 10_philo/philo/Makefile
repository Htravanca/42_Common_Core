NAME = philo
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRC = philo.c philo_routines.c init_data.c init_philos.c init_threads.c init_threads_aux.c monitor_routine.c utils.c utils_libft.c

OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@${CC} ${CFLAGS} ${OBJ} -o $(NAME)
	@echo "${GREEN}$(NAME) created successfully.${RESET}"

%.o: %.c
	@echo "${YELLOW}Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}Cleaning object files...${RESET}"
	@$(RM) $(OBJ)

fclean: clean
	@echo "${RED}Deleting executable and libraries...${RESET}"
	@$(RM) $(NAME)
	@echo "${RED}$(NAME) deleted successfully.${RESET}"

re: fclean all

.PHONY: all, clean, fclean, re, run, va, v