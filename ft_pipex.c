/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:13:02 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/22 16:27:08 by alcierra         ###   ########.fr       */
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

void	ft_pipex(t_command_fd **commands, const int count, char *envp[])
{
	int		index;
	pid_t	child;
	pid_t	*child_array;

	child_array = ft_calloc(sizeof(pid_t), count);
	index = 0;
	while (index < count)
	{
		printf("command ft_pipex >0  %s\n", commands[index]->command);
		printf("command ft_pipex #%d \"%s\"\n", index, commands[index]->command);
		index++;
	}
	index = 0;
	while (index < count)
	{
		printf("command: %s\n", commands[index]->command);
		child = fork();
		if (child < 0)
		{
			perror("Fork: ");
			ft_command_close(commands[index]);
			exit(-1);
		}
		if (child == 0)
			child_process(commands[index], envp);
		ft_command_close(commands[index]);
		child_array[index] = child;
		++index;
	}
	ft_waitpd_all(child_array, count);
	free(child_array);
}
