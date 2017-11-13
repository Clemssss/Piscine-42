# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/19 12:03:11 by clegirar          #+#    #+#              #
#    Updated: 2017/07/19 12:29:19 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_cat

SRCS	=	srcs/main.c				\
			srcs/ft_putstr.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:
			gcc -Wall -Wextra -Werror $(SRCS) -I ./includes -o $(NAME)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
