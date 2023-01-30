# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 14:30:20 by sbarrage          #+#    #+#              #
#    Updated: 2022/05/27 11:39:27 by sbarrage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    = libftprintf.a

SRCS	=	ft_printf.c	ft_putstr.c	ft_putchar.c	ft_control.c	ft_putnbr.c\
			ft_puthex.c\

OBJS	= ${SRCS:.c=.o}

CC	= gcc

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

f:
	${CC} ${CFLAGS} ${SRCS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS} ${Bonus_OBJS}

fclean:	clean
	rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re
