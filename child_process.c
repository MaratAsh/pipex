/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:20:45 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/22 21:43:20 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	child_process(t_command_fd *cmd_i, char **envp)
{
	if (cmd_i->in_fd != -1)
	{
		dup2(cmd_i->in_fd, STDIN_FILENO);
		close(cmd_i->in_fd);
	}
	if (cmd_i->out_fd != -1)
	{
		dup2(cmd_i->out_fd, STDOUT_FILENO);
		close(cmd_i->out_fd);
	}
	ft_execute(cmd_i->command, envp);
	if (cmd_i->in_fd != -1)
		close(STDIN_FILENO);
	if (cmd_i->out_fd != -1)
		close(STDOUT_FILENO);
}
