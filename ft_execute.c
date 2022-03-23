/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:25:56 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/23 12:56:28 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	ft_command_not_exist(char *filename)
{
	write(2, filename, ft_strlen(filename));
	write(2, ": command not found\n", 20);
}

static int	ft_free(char **cmdp, int index)
{
	while (*(cmdp + index))
	{
		free(cmdp[index]);
		++index;
	}
	free(cmdp);
	return (0);
}

int	ft_execute(char *command_params, char **envp)
{
	char	**cmdp;
	int		index;
	char	*path;
	int		res;

	res = 0;
	cmdp = ft_split((const char *) command_params, ' ');
	if (!cmdp)
		return (-1);
	index = 0;
	if (ft_strchr(cmdp[0], '/') || access(cmdp[0], X_OK) == 0)
		path = cmdp[index++];
	else
		path = ft_command_path(cmdp[0], envp);
	if (path)
	{
		res = execve(path, cmdp, envp);
		if (res < 0)
			perror(path);
		free(path);
	}
	else
		ft_command_not_exist(cmdp[0]);
	ft_free(cmdp, index);
	return (res);
}
