# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 19:26:21 by alcierra          #+#    #+#              #
#    Updated: 2022/02/19 12:17:13 by alcierra         ###   ########.fr        #
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
FLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

INCLUDE	=	./libft/libft.a
I_MAKE	=	make -C $(dir $(INCLUDE))

all: lib $(NAME)

lib:
		${I_MAKE} bonus && ${I_MAKE} all

$(NAME): ${OBJS} main.o ${HEADER}
		${CC} $(OBJS) main.o -o $(NAME) -I. $(INCLUDE)

clean:
		rm -rf ${OBJS} ${B_OBJS} main.o
		${I_MAKE} clean

fclean: clean
		rm -rf ${NAME}
		${I_MAKE} fclean

%.o : %.c ${HEADER}
		${CC} ${FLAGS} -c $< -o $@

re: fclean all

test_: all main-test.o
		${CC} -I. $(INCLUDE) $(OBJS) main-test.o -o ${NAME:=-test}

test: all
		./${NAME} ./test/infile "ls -l" "wc -l" ./test/outfile_1
		< ./test/infile ls -l | wc -l > ./test/outfile_1_o
		diff ./test/outfile_1 ./test/outfile_1_o

test_3: all
		./${NAME} infile "ls -l" "cat -e" "wc -l" outfile_2
		< infile ls -l | wc -l | cat -e > outfile_2_o
		diff outfile_2 outfile_2_o

.PHONY: all clean fclean re
