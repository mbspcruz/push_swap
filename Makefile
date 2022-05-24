# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 16:50:36 by mda-cruz          #+#    #+#              #
#    Updated: 2022/05/18 19:11:53 by mda-cruz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

LIB_DIR = ft_printf/

LIBFT_A = ft_printf/libftprintf.a

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

SRC = $(wildcard *.c)

DST = $(SRC:.c=.o)

all: $(NAME)

%.o :%.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(DST)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(DST) $(LIBFT_A) -o $(NAME)

clean:
	@rm -rf $(DST)
	@make -C $(LIB_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean


