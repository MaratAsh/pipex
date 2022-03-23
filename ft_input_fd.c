/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:11:50 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/23 13:31:29 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>

static void	ft_redirect_fd(int fds[2], char **p_argv)
{
	char	*line;
	char	*symbnl;

	write(1, "here_doc > ", 12);
	line = get_next_line(0);
	while (line)
	{
		symbnl = ft_strchr(line, '\n');
		if (symbnl)
			*symbnl = '\0';
		if (ft_strncmp(line, p_argv[1], ft_strlen(line) + 1) == 0)
		{
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
	close(fds[1]);
	close(fds[0]);
}

int	ft_input_fd(char **p_argv)
{
	int		fds[2];
	pid_t	pid;

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
			ft_redirect_fd(fds, p_argv);
			exit(0);
		}
		close(fds[1]);
	}
	else
		fds[0] = open(p_argv[0], O_RDONLY);
	return (fds[0]);
}
