/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:28:28 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/14 14:25:28 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (count < 1 || size < 1)
	{
		count = 1;
		size = 1;
	}
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, size * count);
	return (arr);
}
