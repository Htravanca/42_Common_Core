# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 15:03:09 by hepereir          #+#    #+#              #
#    Updated: 2025/12/01 16:15:31 by hepereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp BitcoinExchange.cpp

OBJ_DIR = obj

OBJS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "${GREEN}$(NAME) created successfully.${RESET}"

$(OBJ_DIR)/%.o: %.cpp
	@echo "${YELLOW}Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "${RED}Cleaning object files...${RESET}"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "${RED}Deleting executable and libraries...${RESET}"
	@rm -f $(NAME)
	@echo "${RED}$(NAME) deleted successfully.${RESET}"

re: fclean all

.PHONY: all clean fclean re