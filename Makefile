# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 19:26:21 by alcierra          #+#    #+#              #
#    Updated: 2022/03/23 14:18:22 by alcierra         ###   ########.fr        #
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
			ft_strnstr.c			ft_input_fd.c

OBJS	=	${SRCS:.c=.o}
FLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

GNL_INCL	=	./get_next_line/get_next_line.a
GNL_MAKE	=	make -C $(dir $(GNL_INCL))

all: $(NAME)

lib:
		${GNL_MAKE} all

$(NAME): lib ${OBJS} main.o ${HEADER}
		${CC} $(OBJS) main.o -o $(NAME) -I. $(GNL_INCL)

clean:
		rm -rf ${OBJS} ${B_OBJS} main.o main-bonus.o
		${GNL_MAKE} clean

fclean: clean
		rm -rf ${NAME}
		${GNL_MAKE} fclean

%.o : %.c ${HEADER}
		${CC} ${FLAGS} -c $< -o $@

re: fclean all

bonus: lib $(NAME) main-bonus.o
		${CC} $(OBJS) main-bonus.o -o $(NAME) -I. $(GNL_INCL)

.PHONY: all clean fclean re bonus
