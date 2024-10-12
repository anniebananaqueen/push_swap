# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 14:37:29 by codespace         #+#    #+#              #
#    Updated: 2024/09/29 18:37:24 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = inc/
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)inc/

COMMANDS_SRC = $(SRC_DIR)commands/push.c \
               $(SRC_DIR)commands/rotate.c \
               $(SRC_DIR)commands/rev_rotate.c \
               $(SRC_DIR)commands/sort_stacks.c \
               $(SRC_DIR)commands/sort_three.c \
               $(SRC_DIR)commands/swap.c

PUSH_SWAP_SRC = $(SRC_DIR)push_swap/handle_errors.c \
                $(SRC_DIR)push_swap/nodes_init.c \
                $(SRC_DIR)push_swap/push_swap.c \
                $(SRC_DIR)push_swap/split.c \
                $(SRC_DIR)push_swap/stack_init.c \
                $(SRC_DIR)push_swap/stack_utils.c 

SRCS = $(COMMANDS_SRC) $(PUSH_SWAP_SRC)
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
