#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 15:15:50 by ftaffore          #+#    #+#              #
#    Updated: 2014/03/23 13:11:15 by ftaffore         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=		test

NAME_L	=		libft.a

CC		=		gcc

RM		=		rm -f

CFLAGS	=		-Werror -Wextra -Wall -W -I libft/includes

SRCS	=		main.c 					\
				get_next.c

SRCS_L	=		libft/ft_memset.c		\
				libft/ft_bzero.c 		\
				libft/ft_memalloc.c 	\
				libft/ft_strcat.c 		\
				libft/ft_strncat.c 		\
				libft/ft_strchr_index.c \
				libft/ft_strlen.c

OBJS	=		$(SRCS:.c=.o)

OBJS_L	=		$(SRCS_L:.c=.o)

all		:		$(NAME_L) $(NAME)

$(NAME_L)	:	$(OBJS_L)
				ar rc $(NAME_L) $(OBJS_L)
				ranlib $(NAME_L)

$(NAME)		:	$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -L. -lft

clean	:
				$(RM) $(OBJS_L) $(OBJS)

fclean	:		clean
				$(RM) $(NAME_L) $(NAME)

re		:		fclean all

.PHONY	:	all clean fclean re
