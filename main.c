/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:33:45 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/10 18:06:02 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>

static void	ft_commands_free(t_command_fd **commands_array, const int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		free(commands_array[index]);
		++index;
	}
	free(commands_array);
}

static int	ft_input_fd(char **p_argv)
{
	int		fds[2];
	pid_t	pid;
	char	*line;
	char	*symbnl;

	if (ft_strncmp(p_argv[0], "here_doc", 9) == 0)
	{
		pipe(fds);
		pid = fork();
		if (pid < 0)
		{
			perror("Fork: ");
			exit(-1);
		}
		if (pid == 0)
		{
			write(1, "here_doc > ", 12);
			line = get_next_line(0);
			printf("%s\n", line);
			while (line)
			{
				symbnl = ft_strchr(line, '\n');
				if (symbnl)
					*symbnl = '\0';
				if (ft_strncmp(line, p_argv[1], ft_strlen(line) + 1) == 0)
				{
					close(fds[1]);
					close(fds[0]);
					free(line);
					break ;
				}
				if (symbnl)
					*symbnl = '\n';
				write(fds[1], line, ft_strlen(line));
				write(1, "here_doc > ", 12);
				free(line);
				line = get_next_line(0);
			}
			exit(0);
		}
	}
	else
		fds[0] = open(p_argv[0], O_RDONLY);
	return (fds[0]);
}

static t_command_fd	**ft_preprocess_args(int p_argc, char **p_argv, int *argc)
{
	t_command_fd	**array;
	int				fd_in;
	int				fd_out;

	fd_in = ft_input_fd(p_argv);
	if (fd_in < 0)
		perror(p_argv[0]);
	if (ft_strncmp(p_argv[0], "append", 7) == 0)
	{
		p_argv++;
		p_argc--;
		fd_out = open(p_argv[p_argc - 1], O_WRONLY | O_APPEND | O_CREAT,
				S_IWUSR | S_IRUSR);
	}
	else
		fd_out = open(p_argv[p_argc - 1], O_TRUNC | O_WRONLY,
				S_IWUSR | S_IRUSR);
	if (fd_out < 0)
		perror(p_argv[p_argc - 1]);
	array = ft_preprocess_commands(p_argv + 1, p_argc - 2, fd_in, fd_out);
	*argc = p_argc;
	return (array);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_command_fd	**array;
	int				p_argc;
	int				res;

	if (argc < 5 + (ft_strncmp(argv[1], "here_doc", 9) == 0))
	{
		ft_putstr_fd(ERR_PARAM_COUNT_MSG, 1);
		return (0);
	}
	array = ft_preprocess_args(argc - 1, argv + 1, &p_argc);
	res = ft_pipex(array, p_argc - 2, envp);
	ft_commands_free(array, p_argc - 2);
	return (res);
}
