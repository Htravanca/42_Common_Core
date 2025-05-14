# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 15:09:04 by hepereir          #+#    #+#              #
#    Updated: 2025/04/03 13:35:02 by hepereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
       ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
       ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
       ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_striteri.c\
       ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
       ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
       ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_strcmp.c \
	   ft_strcat.c ft_strcpy.c ft_strndup.c ft_isalldigit.c
BONUS = ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c \
	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c

OBJS= $(SRCS:.c=.o)
OBJ_B= $(BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I../../inc

all:			$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(OBJS) $(OBJ_B)
				$(RM) $(NAME)
				ar rcs $(NAME) $(OBJS) $(OBJ_B)

clean:
				$(RM) $(OBJS) $(OBJ_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all bonus clean fclean re
