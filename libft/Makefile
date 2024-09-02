# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 14:23:48 by codespace         #+#    #+#              #
#    Updated: 2024/08/27 13:41:08 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc
SRC_DIR = src/
OBJ_DIR = objs/
INCLUDES = inc/

SRCS = $(wildcard $(SRC_DIR)*.c)
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "libft compiled successfully into $(NAME)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
