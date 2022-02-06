/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_envp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:32:23 by alcierra          #+#    #+#             */
/*   Updated: 2022/01/30 16:45:18 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_search_envp(char *envp[], const char *param_name)
{
	char	*result;
	size_t	param_len;

	param_len = ft_strlen((char *) param_name);
	if (param_len == 0)
		return (NULL);
	while (*envp)
	{
		result = ft_strnstr(*envp, param_name, param_len);
		if (result != NULL)
			return (result);
		++envp;
	}
	return (NULL);
}

char	*ft_search_envp_shift(char *envp[], const char *param_name)
{
	char	*result;
	size_t	param_len;

	param_len = ft_strlen((char *) param_name);
	if (param_len == 0)
		return (NULL);
	while (*envp)
	{
		result = ft_strnstr(*envp, param_name, param_len);
		if (result != NULL)
			return (result + param_len + 1);
		++envp;
	}
	return (NULL);
}
