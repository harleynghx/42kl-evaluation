/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:23:56 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/24 10:38:29 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

int	initall(t_ps *ps, int argc, char **argv)
{
	ps->argc = argc;
	ps->argv = argv;
	ps->itemcount = argc - 1;
	ps->iargv = malloc(ps->itemcount * sizeof(int) + 1);
	ps->chunklets = malloc(20 * sizeof(int));
	ps->steps = 0;
	ps->fd = open("./temp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ps->input = NULL;
	return (1);
}

void	initlinkedlist(t_ps *ps, t_list **stack)
{
	int		i;

	i = 0;
	while (i < ps->argc - 1)
		ft_lstadd_back(stack, ft_lstnew(&ps->iargv[i++]));
}
