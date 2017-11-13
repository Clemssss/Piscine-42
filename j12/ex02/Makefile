# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/19 13:32:26 by clegirar          #+#    #+#              #
#    Updated: 2017/07/25 18:57:03 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_tail

SRCS	=	srcs/main.c					\
			srcs/ft_atoi.c				\
			srcs/follow.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:
			gcc -Wall -Wextra -Werror $(SRCS) -I ./includes -o $(NAME)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
