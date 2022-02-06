/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:06:59 by alcierra          #+#    #+#             */
/*   Updated: 2022/01/30 18:09:13 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_command_path(char *command, char *envp[])
{
	char	*envpath;
	char	**paths;
	int		paths_shift;
	char	*r_path;
	char	finded;

	command = ft_strjoin("/", command);
	finded = 0;
	envpath = ft_search_envp_shift(envp, "PATH");
	if (envpath == NULL)
		envpath = "/usr/local/bin:/usr/bin:/bin:/usr/sbin";
	paths = ft_split(envpath, ':');
	if (!paths)
		return (NULL);
	paths_shift = 0;
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
	free(paths);
	free(command);
	return (r_path);
}
