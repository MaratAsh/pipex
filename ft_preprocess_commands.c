/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:23:44 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/07 00:03:16 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_command_fd	**ft_preprocess_commands(char *commands[], int count,
					int fd_in, int fd_out)
{
	t_command_fd	**array;
	int				index;
	int				fds[2];

	array = ft_calloc(sizeof(t_command_fd *), count);
	index = 0;
	while (index < count)
	{
		array[index] = ft_create_commfd(commands[index]);
		if (index == 0)
			array[0]->in_fd = fd_in;
		else
		{
			array[index]->in_fd = fds[0];
		}
		if (index == count - 1)
			array[index]->out_fd = fd_out;
		else
		{
			pipe(fds);
			array[index]->out_fd = fds[1];
		}
		++index;
	}
	return (array);
}
