/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:13:02 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/06 22:57:22 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_pipex(t_command_fd *commands[], int count, char *envp[])
{
	int		index;
	pid_t	child;
	pid_t	*child_array;
	int		status;

	child_array = ft_calloc(sizeof(pid_t), count);
	index = 0;
	while (index < count)
	{
		child = fork();
		if (child < 0)
		{
			perror("Fork: ");
			close(commands[index]->in_fd);
			close(commands[index]->out_fd);
			exit(-1);
		}
		if (child == 0)
		{
			child_process(commands[index], envp);
			exit(0);
		}
		close(commands[index]->in_fd);
		close(commands[index]->out_fd);
		child_array[index] = child;
		++index;
	}
	index = 0;
	while (index < count)
	{
		waitpid(child_array[index], &status, 0);
		++index;
	}
	free(child_array);
}
