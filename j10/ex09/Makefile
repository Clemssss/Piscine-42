# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/17 10:50:52 by clegirar          #+#    #+#              #
#    Updated: 2017/07/17 16:35:19 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_advanced_do-op

SRCS	=	srcs/main.c			\
			srcs/ft_putnbr.c	\
			srcs/ft_strcmp.c	\
			srcs/ft_atoi.c		\
			srcs/calculs.c		\
			srcs/calculs2.c

FPO		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:
			gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME) -I ./

clean	:
			rm -rf $(FPO)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
