# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 19:26:21 by alcierra          #+#    #+#              #
#    Updated: 2022/03/20 22:52:51 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
HEADER	=	ft_pipex.h
SRCS	=	ft_pipex.c				child_process.c		\
			ft_execute.c			ft_create_commfd.c	\
			ft_search_envp.c		ft_command_path.c	\
			ft_preprocess_commands.c					\
			ft_process_errors.c							\
			ft_strchr.c				ft_strjoin.c		\
			ft_strlcpy.c			ft_strlen.c			\
			ft_strncmp.c			ft_putstr_fd.c		\
			ft_memcpy.c				ft_calloc.c			\
			ft_memset.c				ft_split.c			\
			ft_strnstr.c

OBJS	=	${SRCS:.c=.o}
FLAGS	=	-Wall -Wextra -Werror -g
CC		=	gcc

GNL_INCL	=	./get_next_line/get_next_line.a
GNL_MAKE	=	make -C $(dir $(GNL_INCL))

all: lib $(NAME)

lib:
		${GNL_MAKE} all

$(NAME): ${OBJS} main.o ${HEADER}
		${CC} $(OBJS) main.o -o $(NAME) -I. $(GNL_INCL)

clean:
		rm -rf ${OBJS} ${B_OBJS} main.o
		${GNL_MAKE} clean

fclean: clean
		rm -rf ${NAME}
		${GNL_MAKE} fclean

%.o : %.c ${HEADER}
		${CC} ${FLAGS} -c $< -o $@

re: fclean all

bonus: all


.PHONY: all clean fclean re bonus
