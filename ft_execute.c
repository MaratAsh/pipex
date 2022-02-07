/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:25:56 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/07 14:01:33 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_execute(char *command_params, char **envp)
{
	char	**cmdp;
	int		index;
	char	*path;

	cmdp = ft_split((const char *) command_params, ' ');
	if (!cmdp)
		return (-1);
	index = 0;
	if (ft_strchr(cmdp[0], '/') || access(cmdp[0], X_OK) == 0)
		path = cmdp[index++];
	else
		path = ft_command_path(cmdp[0], envp);
	execve(path, cmdp, envp);
	free(path);
	while (*(cmdp + index))
	{
		free(cmdp[index]);
		++index;
	}
	free(cmdp);
	return (0);
}
