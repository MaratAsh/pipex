/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:14:48 by alcierra          #+#    #+#             */
/*   Updated: 2022/02/19 12:34:11 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_validate_fd(int fd, char *file_name)
{
	size_t	len;
	char	*str;

	if (fd > 0)
		return (1);
	len = ft_strlen(file_name);
	str = (char *) malloc(19 + len + 1 + 1);
	if (!str)
	{
		ft_putstr_fd("permission denied: ", 1);
		ft_putstr_fd(file_name, 1);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_memcpy(str, "permission denied: ", 19);
		ft_memcpy(str + 19, file_name, len);
		str[19 + len] = '\n';
		str[19 + len + 1] = '\0';
		ft_putstr_fd(str, 1);
		free(str);
	}
	return (0);
}
