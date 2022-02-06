/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:10:52 by alcierra          #+#    #+#             */
/*   Updated: 2022/01/18 20:29:09 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *))
{
	t_dlist	*start;
	t_dlist	*curr;

	start = NULL;
	if (dlst)
	{
		start = ft_dlstnew(f(dlst->content));
		dlst = dlst->next;
		curr = start;
	}
	while (dlst)
	{
		if (curr)
			curr->next = ft_dlstnew(f(dlst->content));
		else
			break ;
		if (curr && curr->next)
		{
			curr->next->prev = curr;
			curr = curr->next;
		}
		dlst = dlst->next;
	}
	return (start);
}
