# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 14:37:29 by codespace         #+#    #+#              #
#    Updated: 2024/08/27 13:32:18 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft/libft.a

INC = inc/

SRC_DIR = srcs/
OBJ_DIR = objs/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC) 

COMMANDS_DIR = $(SRC_DIR)commands/push.c \
				$(SRC_DIR)commands/rotate.c \
				$(SRC_DIR)commands/sort_stacks.c \
				$(SRC_DIR)commands/sort_three.c \
				$(SRC_DIR)commands/swap.c \

PUSH_SWAP_DIR = 	$(SRC_DIR)push_swap/handle_errors.c \
					$(SRC_DIR)push_swap/init_a_to_b.c \
					$(SRC_DIR)push_swap/init_b_to_a.c \
					$(SRC_DIR)push_swap/push_swap.c \
					$(SRC_DIR)push_swap/split.c \
					$(SRC_DIR)push_swap/stack_init.c \
					$(SRC_DIR)push_swap/stack_utils.c \

SRCS = $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start: all

$(LIBFT):
	make -C ./libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: start all clean fclean re 