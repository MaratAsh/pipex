/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:04:22 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/09 20:46:10 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *) src));
	while (src[i])
	{
		if (i == size - 1)
			break ;
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen((char *) src));
}
