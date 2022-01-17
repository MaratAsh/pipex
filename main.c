/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:33:45 by alcierra          #+#    #+#             */
/*   Updated: 2022/01/17 19:53:55 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include "libft/libft.h"

#define ERR_PARAM_COUNT_MSG "Usage example:\
\n./pipex infile \"ls -l\" \"wc -l\" outfile\n"

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc != 5)
	{
		ft_putstr_fd(ERR_PARAM_COUNT_MSG, 1);
		return (0);
	}
	return (0);
}
