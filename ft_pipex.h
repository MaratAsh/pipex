/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:26:57 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/22 15:01:50 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define ERR_PARAM_COUNT_MSG "Usage example:\n\
./pipex infile \"ls -l\" \"wc -l\" outfile\n\
< infile ls -l | wc -l > outfile\n"

typedef struct s_command_fd
{
	int		fd;
	int		in_fd;
	int		out_fd;
	char	*command;
	char	**params;
}				t_command_fd;

t_command_fd	**ft_preprocess_commands(char *commands[], const int count,
					int fd_in, int fd_out);
void			ft_pipex(t_command_fd **commands, int count, char *envp[]);
void			child_process(t_command_fd *cmd_i, char **envp);
int				ft_execute(char *command_params, char **envp);
char			*ft_search_envp(char *envp[], const char *param_name);
char			*ft_search_envp_shift(char *envp[], const char *param_name);
char			*ft_command_path(char *command, char *envp[]);
t_command_fd	*ft_create_commfd(char *cmd);

// ft_process_errors.c - for errors processing
int				ft_validate_fd(int fd, char *file_name);

#endif
