# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 16:50:36 by mda-cruz          #+#    #+#              #
#    Updated: 2022/05/29 15:26:36 by mda-cruz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 

FT_PRT = ft_printf/

PRNT_A = ft_printf/libftprintf.a

SRCS = $(wildcard *.c)

NAME = push_swap

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

%.o:%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

all: *.h
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@make -C $(FT_PRT)
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(PRNT_A) -o $(NAME)

clean:
	rm -rf *.o
	@make -C $(FT_PRT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT_PRT) clean

re: fclean all
