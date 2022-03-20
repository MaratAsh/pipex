/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:45:20 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/14 14:23:11 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*temp_dst;

	if (dst == (void *) 0 && src == (void *) 0)
		return (dst);
	temp_dst = (char *) dst;
	i = 0;
	while (i < n)
	{
		temp_dst[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}
