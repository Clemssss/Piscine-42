# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 12:32:02 by clegirar          #+#    #+#              #
#    Updated: 2017/07/26 21:16:56 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq

SRCS	=	srcs/main.c						\
			srcs/ft_split_whitespaces.c		\
			srcs/algo.c						\
			srcs/lib.c						\
			srcs/read_file.c				\
			srcs/call_algo.c				\
			srcs/ft_atoi.c

FPO		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:
			gcc -Wall -Wextra -Werror $(SRCS) -I ./includes/ -o $(NAME)

clean	:
			rm -rf $(FPO)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
