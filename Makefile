# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 19:26:21 by alcierra          #+#    #+#              #
#    Updated: 2022/03/10 16:16:59 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
HEADER	=	ft_pipex.h
SRCS	=	ft_pipex.c				child_process.c		\
			ft_execute.c			ft_create_commfd.c	\
			ft_search_envp.c		ft_command_path.c	\
			ft_preprocess_commands.c					\
			ft_process_errors.c

OBJS	=	${SRCS:.c=.o}
FLAGS	=	-Wall -Wextra -Werror -g
CC		=	gcc

LIB_INCL	=	./libft/libft.a
GNL_INCL	=	./get_next_line/get_next_line.a
LIB_MAKE	=	make -C $(dir $(LIB_INCL))
GNL_MAKE	=	make -C $(dir $(GNL_INCL))

all: lib $(NAME)

lib:
		${LIB_MAKE} bonus && ${LIB_MAKE} all
		${GNL_MAKE} all

$(NAME): ${OBJS} main.o ${HEADER}
		${CC} $(OBJS) main.o -o $(NAME) -I. $(LIB_INCL) $(GNL_INCL)

clean:
		rm -rf ${OBJS} ${B_OBJS} main.o
		${LIB_MAKE} clean
		${GNL_MAKE} clean

fclean: clean
		rm -rf ${NAME}
		${LIB_MAKE} fclean
		${GNL_MAKE} fclean

%.o : %.c ${HEADER}
		${CC} ${FLAGS} -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
