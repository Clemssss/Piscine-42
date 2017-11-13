# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 21:13:13 by clegirar          #+#    #+#              #
#    Updated: 2017/07/17 16:34:17 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	do-op

SRCS	=	srcs/do_op.c		\
			srcs/calculs.c		\
			srcs/ft_atoi.c		\
			srcs/ft_putnbr.c	\
			srcs/ft_strcmp.c

FPO		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:
			gcc -Wall -Wextra -Werror $(SRCS) -I ./ -o $(NAME)

clean	:
			rm -rf $(FPO)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
