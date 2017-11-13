# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 20:18:44 by clegirar          #+#    #+#              #
#    Updated: 2017/07/23 23:27:30 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	eval_expr

SRCS	=	srcs/main.c					\
			srcs/lib.c					\
			srcs/eval_expr.c			\
			srcs/remp_list_operator.c	\
			srcs/result.c				\
			srcs/ft_atoi.c				\
			srcs/resolve.c				\
			srcs/calculs.c				\
			srcs/lists.c

FPO		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:
			gcc -Wall -Wextra -Werror $(SRCS) -I ./includes/ -o $(NAME)

clean	:
			rm -rf $(FPO)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
