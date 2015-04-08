#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 15:15:50 by ftaffore          #+#    #+#              #
#    Updated: 2015/04/07 13:45:23 by ftaffore         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_L		=	libft.a

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Werror -Wextra -Wall -W  -Iincludes


SRCS_L		=	ft_memset.c			\
				ft_bzero.c 			\
				ft_memalloc.c 		\
				ft_strcat.c 		\
				ft_strncat.c 		\
				ft_strchr_index.c 	\
				ft_putstr.c 		\
				ft_strlen.c

OBJS_L		=	$(SRCS_L:.c=.o)

all			:	$(NAME_L)

$(NAME_L)	:	$(OBJS_L)
				ar rc $(NAME_L) $(OBJS_L)
				ranlib $(NAME_L)

clean		:
				$(RM) $(OBJS_L)

fclean		:	clean
				$(RM) $(NAME_L)

re			:	fclean all

.PHONY		:	all clean fclean re
