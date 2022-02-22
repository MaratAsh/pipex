/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:13:02 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/22 23:00:46 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	ft_waitpd_all(pid_t	*child_array, const int count)
{
	int	index;
	int	status;

	index = 0;
	while (index < count)
	{
		waitpid(child_array[index], &status, 0);
		++index;
	}
}

static void	ft_command_close(t_command_fd *command)
{
	close(command->in_fd);
	close(command->out_fd);
}

static void	ft_child_or_parent(pid_t pid, t_command_fd *cmd,
				char **envp, pid_t *child_array)
{
	int	res;

	if (pid < 0)
	{
		perror("Fork: ");
		ft_command_close(cmd);
		exit(-1);
	}
	if (pid == 0)
	{
		res = child_process(cmd, envp);
		free(child_array);
		exit(res);
	}
}

int	ft_pipex(t_command_fd **commands, const int count, char *envp[])
{
	int		index;
	pid_t	child;
	pid_t	*child_array;

	child_array = ft_calloc(sizeof(pid_t), count);
	index = 0;
	while (index < count)
	{
		child = fork();
		ft_child_or_parent(child, *(commands + index), envp, child_array);
		ft_command_close(commands[index]);
		child_array[index] = child;
		++index;
	}
	ft_waitpd_all(child_array, count);
	free(child_array);
	return (0);
}
