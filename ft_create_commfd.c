/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_commfd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:59:29 by alcierra          #+#    #+#             */
/*   Updated: 2022/01/26 16:04:44 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_command_fd	*ft_create_commfd(char *cmd)
{
	t_command_fd	*elem;

	elem = malloc(sizeof(t_command_fd *));
	elem->fd = -1;
	elem->in_fd = -1;
	elem->out_fd = -1;
	elem->command = cmd;
	return (elem);
}
