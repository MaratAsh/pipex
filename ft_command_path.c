/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:06:59 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/07 18:54:16 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static char	*ft_find_path(char **paths, char *command)
{
	int		paths_shift;
	int		finded;
	char	*r_path;

	paths_shift = 0;
	finded = 0;
	while (*(paths + paths_shift))
	{
		if (finded == 0)
			r_path = ft_strjoin(*(paths + paths_shift), command);
		if (access(r_path, X_OK) == 0)
		{
			finded = 1;
		}
		if (finded == 0)
		{
			free(r_path);
			r_path = NULL;
		}
		free(*(paths + paths_shift));
		++paths_shift;
	}
	return (r_path);
}

char	*ft_command_path(char *command, char *envp[])
{
	char	*envpath;
	char	**paths;
	char	*r_path;

	command = ft_strjoin("/", command);
	if (!command)
		return (NULL);
	envpath = ft_search_envp_shift(envp, "PATH");
	if (envpath == NULL)
		envpath = "/usr/local/bin:/usr/bin:/bin:/usr/sbin";
	paths = ft_split(envpath, ':');
	if (!paths)
		return (NULL);
	r_path = ft_find_path(paths, command);
	free(paths);
	free(command);
	return (r_path);
}
