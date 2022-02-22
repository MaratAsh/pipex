/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:33:45 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/22 21:38:04 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <fcntl.h>

static void ft_commands_free(t_command_fd **commands_array, const int count)
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

int	main(int argc, char *argv[], char *envp[])
{
	int				fd_in;
	int				fd_out;
	t_command_fd	**array;
	char			**p_argv;
	int				p_argc;

	if (argc < 5)
	{
		ft_putstr_fd(ERR_PARAM_COUNT_MSG, 1);
		return (0);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		p_argv = argv + 2;
		p_argc = argc - 2;
		fd_out = open(p_argv[p_argc - 1], O_APPEND, S_IWUSR | S_IRUSR);
	}
	else
	{
		p_argv = argv + 1;
		p_argc = argc - 1;
		fd_out = open(argv[p_argc], O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
	}
	fd_in = open(p_argv[0], O_RDONLY);
	if (ft_validate_fd(fd_in, p_argv[0]) == 0
		|| ft_validate_fd(fd_out, p_argv[p_argc - 1]) == 0)
		return (0);
	array = ft_preprocess_commands(p_argv + 1, p_argc - 2, fd_in, fd_out);
	ft_pipex(array, p_argc - 2, envp);
	ft_commands_free(array, p_argc - 2);
	return (0);
}
