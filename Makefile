# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 22:36:02 by digil-pa          #+#    #+#              #
#    Updated: 2023/07/03 14:36:01 by digil-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS	=	lists.c			\
			push_ab.c		\
			push_swap.c		\
			rotation.c		\
			rrotate.c		\
			sort_3.c		\
			sort_5.c		\
			swaps.c			\
			100sort.c		\
			aux_100sort.c	\
			aux2_100sort.c	\
			check.c			\
			checker.c		\
			
OBJS	=	$(SRCS:.c=.o)

CC	=	cc

RM	=	rm	-f

CFLAGS	=	-Wall	-Wextra	-Werror	-g

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC)	$(CFLAGS)	$(OBJS)	-o	$(NAME)

clean:
			$(RM)	$(OBJS)

fclean:		clean
			$(RM)	$(NAME)

re:			fclean $(NAME)

.PHONY:		all	clean	fclean	re