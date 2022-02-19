/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:33:45 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/19 12:16:50 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <fcntl.h>

int	main(int argc, char *argv[], char *envp[])
{
	int				fd_in;
	int				fd_out;
	t_command_fd	**array;

	if (argc < 5)
	{
		ft_putstr_fd(ERR_PARAM_COUNT_MSG, 1);
		return (0);
	}
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT, S_IWUSR | S_IREAD);
	if (ft_validate_fd(fd_in, argv[1]) == 0
		|| ft_validate_fd(fd_out, argv[argc - 1]) == 0)
		return (0);
	array = ft_preprocess_commands(argv + 2, argc - 3, fd_in, fd_out);
	ft_pipex(array, argc - 3, envp);
	free(array);
	return (0);
}
