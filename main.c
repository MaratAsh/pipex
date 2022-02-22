/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:33:45 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/22 22:51:48 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
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

static t_command_fd	**ft_preprocess_args(int p_argc, char **p_argv, int *argc)
{
	t_command_fd	**array;
	int				fd_in;
	int				fd_out;

	if (ft_strncmp(p_argv[0], "here_doc", 9) == 0)
	{
		p_argv++;
		p_argc--;
		fd_out = open(p_argv[p_argc - 1], O_WRONLY | O_APPEND | O_CREAT,
				S_IWUSR | S_IRUSR);
	}
	else
		fd_out = open(p_argv[p_argc - 1], O_TRUNC | O_WRONLY | O_CREAT,
				S_IWUSR | S_IRUSR);
	fd_in = open(p_argv[0], O_RDONLY);
	if (ft_validate_fd(fd_in, p_argv[0]) == 0
		|| ft_validate_fd(fd_out, p_argv[p_argc - 1]) == 0)
		return (0);
	array = ft_preprocess_commands(p_argv + 1, p_argc - 2, fd_in, fd_out);
	*argc = p_argc;
	return (array);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_command_fd	**array;
	int				p_argc;
	int				res;

	if (argc < 5)
	{
		ft_putstr_fd(ERR_PARAM_COUNT_MSG, 1);
		return (0);
	}
	array = ft_preprocess_args(argc - 1, argv + 1, &p_argc);
	res = ft_pipex(array, p_argc - 2, envp);
	ft_commands_free(array, p_argc - 2);
	return (res);
}
