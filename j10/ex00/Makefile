# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 09:51:50 by clegirar          #+#    #+#              #
#    Updated: 2017/07/13 20:40:15 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	compil

LIB		=	libft.a

SRCS	=	srcs/ft_putchar.c		\
			srcs/ft_putstr.c		\
			srcs/ft_strcmp.c		\
			srcs/ft_strlen.c		\
			srcs/ft_swap.c

FPO		=	ft_putchar.o	\
			ft_putstr.o		\
			ft_strcmp.o		\
			ft_strlen.o		\
			ft_swap.o

all	:	$(LIB)

$(NAME)	:
			gcc -c $(SRCS) -I includes/

$(LIB)	:	$(NAME)
			ar rc $(LIB) $(FPO)

clean	:
			rm -rf $(FPO)

fclean	:	clean
			rm -rf $(LIB)

re		:	fclean all
