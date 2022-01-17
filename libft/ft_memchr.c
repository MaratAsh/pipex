/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:16:27 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/12 15:45:16 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	if ((unsigned char) c == 0 && ((char *) s)[n - 1] == '\0')
		return ((char *) s + n - 1);
	while (i < n)
	{
		if (((char *) s)[i] == c)
			return ((void *) s + i);
		i++;
	}
	return ((void *) 0);
}
