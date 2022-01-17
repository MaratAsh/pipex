# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 19:26:21 by alcierra          #+#    #+#              #
#    Updated: 2022/01/17 19:29:00 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
HEADER	=	ft_pipex.h
SRCS	=	main.c

OBJS	=	${SRCS:.c=.o}
FLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	./libft/libft.a
I_MAKE	=	make -C $(dir $(INCLUDE))

all: lib $(NAME)

lib:
		${I_MAKE} bonus
		${I_MAKE}

$(NAME): ${OBJS} ${HEADER}
		cc -I. $(INCLUDE) $(OBJS) -o $(NAME)

clean:
		rm -rf ${OBJS} ${B_OBJS}
		${I_MAKE} clean

fclean: clean
		rm -rf ${NAME}
		${I_MAKE} fclean

%.o : %.c ${HEADER}
		cc ${FLAGS} -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
