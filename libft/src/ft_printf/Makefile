# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 20:43:04 by apatkano          #+#    #+#              #
#    Updated: 2024/07/05 13:46:17 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRCS = sources/ft_printf.c sources/ft_putchar.c sources/ft_putstr.c sources/ft_ptr.c sources/ft_putnbr.c sources/ft_putnbrun.c sources/ft_hexlow.c sources/ft_hexupp.c
OBJS = $(SRCS:.c=.o)
LIB = libftprintf.a

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re
