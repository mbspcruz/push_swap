# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mda-cruz <user@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 13:22:20 by mda-cruz          #+#    #+#              #
#    Updated: 2021/07/16 23:01:52 by mda-cruz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h 

DEP_HEADER = libft/libft.h 

CC = gcc

CFLAGS = -c -g -Wall -Wextra -Werror

LIB_FLAGS = -rcs

SRC = $(wildcard *.c)

DST = $(SRC:.c=.o)

DEP_SRC = $(wildcard libft/*.c)

DEP_DST = $(DEP_SRC:.c=.o)

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(DST) $(DEP_DST)
		ar $(LIB_FLAGS) $@ $^

%.o : %.c $(HEADER)
		$(CC) $(CFLAGS) $< -o $@

libft/%.o : libft/%.c $(DEP_HEADER)
		$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f $(DST) $(DEP_DST)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re