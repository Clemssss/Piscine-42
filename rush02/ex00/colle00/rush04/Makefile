# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 09:55:25 by clegirar          #+#    #+#              #
#    Updated: 2017/07/22 10:12:17 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../../colle-04

SRCS	=	rush04.c			\
			../ft_putchar.c		\
			../main.c

FPO		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:
			gcc -Wall -Wextra -Werror $(SRCS) -I ../ -o $(NAME)

clean	:
			rm -rf $(FPO)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
