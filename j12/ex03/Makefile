# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/19 16:39:09 by clegirar          #+#    #+#              #
#    Updated: 2017/07/21 11:11:27 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_hexdump

SRCS	=	srcs/main.c					\
			srcs/ft_strcmp.c			\
			srcs/ft_convert_base.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:
			gcc -Wall -Wextra -Werror $(SRCS) -I ./includes -o $(NAME)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
