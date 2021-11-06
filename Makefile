# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 20:51:34 by benmoham          #+#    #+#              #
#    Updated: 2021/10/24 16:32:24 by benmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=    ft_printf.c			\
		ft_conv.c		\
		ft_util_printf.c 	\
		ft_util_printf2.c	\
		
NAME= libftprintf.a

OBJETS= ${SRC:.c=.o}

gcc=gcc -Werror -Wall -Wextra

%.o: %.c
	${gcc} -o $@ -c $<

$(NAME):    ${OBJETS}
			ar -rc ${NAME} $^
			ranlib ${NAME}

all: ${NAME}

re: fclean all

clean:
		rm -f ${OBJETS}

fclean: clean
		rm -f ${NAME}

.PHONY: all clean fclean re