# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 14:23:48 by codespace         #+#    #+#              #
#    Updated: 2024/09/05 12:49:13 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc

SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = objs/

FTIS_DIR = $(SRC_DIR)ft_is/ft_isalnum.c \
           $(SRC_DIR)ft_is/ft_isalpha.c \
           $(SRC_DIR)ft_is/ft_isascii.c \
           $(SRC_DIR)ft_is/ft_isdigit.c \
           $(SRC_DIR)ft_is/ft_isprint.c 

FTMEM_DIR = $(SRC_DIR)ft_mem/ft_bzero.c \
            $(SRC_DIR)ft_mem/ft_calloc.c \
            $(SRC_DIR)ft_mem/ft_memchr.c \
			$(SRC_DIR)ft_mem/ft_memcpy.c \
            $(SRC_DIR)ft_mem/ft_memcmp.c \
            $(SRC_DIR)ft_mem/ft_memmove.c \
            $(SRC_DIR)ft_mem/ft_memset.c 

FTPUT_DIR = $(SRC_DIR)ft_put/ft_putchar_fd.c \
            $(SRC_DIR)ft_put/ft_putendl_fd.c \
            $(SRC_DIR)ft_put/ft_putnbr_fd.c \
            $(SRC_DIR)ft_put/ft_putstr_fd.c \
			$(SRC_DIR)ft_put/ft_putchar.c \
			$(SRC_DIR)ft_put/ft_putnbr.c \
			$(SRC_DIR)ft_put/ft_putnbrun.c \
			$(SRC_DIR)ft_put/ft_putstr.c 

FTTO_DIR = $(SRC_DIR)ft_to/ft_atoi.c \
           $(SRC_DIR)ft_to/ft_itoa.c \
           $(SRC_DIR)ft_to/ft_tolower.c \
           $(SRC_DIR)ft_to/ft_toupper.c \
		   $(SRC_DIR)ft_to/ft_hexlow.c \
		   $(SRC_DIR)ft_to/ft_hexupp.c

FTSTR_DIR = $(SRC_DIR)ft_str/ft_split.c \
            $(SRC_DIR)ft_str/ft_strchr.c \
            $(SRC_DIR)ft_str/ft_strdup.c \
            $(SRC_DIR)ft_str/ft_striteri.c \
            $(SRC_DIR)ft_str/ft_strjoin.c \
            $(SRC_DIR)ft_str/ft_strlcat.c \
            $(SRC_DIR)ft_str/ft_strlcpy.c \
            $(SRC_DIR)ft_str/ft_strlen.c \
            $(SRC_DIR)ft_str/ft_strmapi.c \
            $(SRC_DIR)ft_str/ft_strncmp.c \
            $(SRC_DIR)ft_str/ft_strnstr.c \
            $(SRC_DIR)ft_str/ft_strrchr.c \
            $(SRC_DIR)ft_str/ft_strtrim.c \
            $(SRC_DIR)ft_str/ft_substr.c 

FTLST_DIR = $(SRC_DIR)ft_lst/ft_lstadd_back.c \
            $(SRC_DIR)ft_lst/ft_lstadd_front.c \
            $(SRC_DIR)ft_lst/ft_lstclear.c \
            $(SRC_DIR)ft_lst/ft_lstdelone.c \
            $(SRC_DIR)ft_lst/ft_lstiter.c \
            $(SRC_DIR)ft_lst/ft_lstlast.c \
            $(SRC_DIR)ft_lst/ft_lstmap.c \
            $(SRC_DIR)ft_lst/ft_lstnew.c \
            $(SRC_DIR)ft_lst/ft_lstsize.c 

FTPRINTF_DIR = $(SRC_DIR)ft_printf/ft_printf.c \
               $(SRC_DIR)ft_printf/ft_ptr.c \

SRCS = $(FTIS_DIR) $(FTMEM_DIR) $(FTPUT_DIR) $(FTTO_DIR) $(FTSTR_DIR) $(FTLST_DIR) $(FTPRINTF_DIR)
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "libft compiled successfully into $(NAME)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
