NAME = minishell
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iinc
READLINE = -lreadline -lncurses

LIBFT = aux/libft/libft.a

PARSING = parsing/
EXPANDER = expander/
BUILTINS = builtins/
LEXER = lexer/
CMD = run_cmd/

SRC = minishell.c $(PARSING)parsing.c $(PARSING)parsing2.c $(PARSING)aux_parsing/aux_parsing.c $(SRC_BUILTINS) $(SRC_ENV_CPY) $(RUN_CMD) $(PARSING)aux_parsing/ft_lst.c $(PARSING)aux_parsing/free_and_exit.c $(PARSING)aux_parsing/ft_lst2.c $(PARSING)redir.c $(PARSING)parse_quotes.c $(PARSING)/aux_parsing/free_and_exit2.c $(EXPANDER)expand_variable.c $(EXPANDER)aux_expander/ft_strncpy.c $(EXPANDER)aux_expander/expand_aux.c $(EXPANDER)aux_expander/expand_aux2.c $(PARSING)remove_quotes.c signals/signal_handler.c $(PARSING)check_list.c $(LEXER)lexer.c $(LEXER)validate_cmd.c

SRC_BUILTINS = $(BUILTINS)cd.c $(BUILTINS)cd2.c $(BUILTINS)echo.c $(BUILTINS)env.c $(BUILTINS)export.c $(BUILTINS)export2.c $(BUILTINS)export3.c $(BUILTINS)pwd.c $(BUILTINS)unset.c $(BUILTINS)exit.c $(BUILTINS)exit2.c

SRC_ENV_CPY = env_cpy/new_env.c env_cpy/new_env2.c

RUN_CMD = $(CMD)run_cmd.c $(CMD)run_cmd2.c $(CMD)run_cmd_env_arr.c $(CMD)run_cmd_path.c $(CMD)run_cmd_redir.c $(CMD)run_cmd_builtins.c $(CMD)run_cmd_files.c $(CMD)run_cmd_heredoc.c $(CMD)run_cmd_utils.c $(CMD)run_cmd_heredoc2.c $(CMD)run_cmd_wait.c

OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(LIBFT):
	@echo "${YELLOW}Compiling libft...${RESET}"
	@make -s -C ./aux/libft

$(NAME): $(OBJ) $(LIBFT)
	@echo "${YELLOW}Linking object files and libraries...${RESET}"
	@${CC} ${CFLAGS} ${OBJ} $(LIBFT) -o $(NAME) ${READLINE}
	@echo "${GREEN}$(NAME) created successfully.${RESET}"

%.o: %.c
	@echo "${YELLOW}Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}Cleaning object files...${RESET}"
	@$(RM) $(OBJ)
	@make clean -s -C ./aux/libft

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

#va:
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --suppressions=readline.supp ./$(NAME)

va: $(NAME)
	@valgrind --suppressions=readline.supp --leak-check=full --track-fds=yes --show-leak-kinds=all ./$(NAME)

v: all
	@valgrind ./$(NAME)

.PHONY: all, clean, fclean, re, run, va, v