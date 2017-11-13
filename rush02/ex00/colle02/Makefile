# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 10:16:27 by clegirar          #+#    #+#              #
#    Updated: 2017/07/23 11:55:37 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../colle-2

SRCS	=	main.c					\
			recup_size.c			\
			colles.c				\
			lib.c					\
			read_file.c				\
			colle00/rush00.c		\
			colle00/rush01.c		\
			colle00/rush02.c		\
			colle00/rush03.c		\
			colle00/rush04.c

FPO		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:
			gcc -Wall -Wextra -Werror $(SRCS) -I ./ -o $(NAME)

clean	:
			rm -rf $(FPO)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
