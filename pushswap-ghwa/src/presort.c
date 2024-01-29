/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:55:09 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/24 13:02:14 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	set_chunks(t_ps *ps, int chunks)
{
	int	*arr;
	int	chunksize;
	int	i;
	int	j;

	i = 1;
	j = 0;
	arr = bubblesort(ps);
	chunksize = ps->itemcount / chunks;
	while (i < ps->itemcount)
	{
		if (i % chunksize == 0 && j < (chunks - 1))
		{
			ps->chunklets[j] = arr[i + 1];
			j++;
		}
		i++;
	}
	ps->chunklets[j] = arr[i - 1];
	free (arr);
}

void	pushbottom(t_list **stacka, t_list **stackb, t_ps *ps, int i)
{
	t_list	*lowest;

	lowest = ft_lstlast(*stacka);
	if ((*(int *)lowest->content) <= ps->chunklets[i])
	{
		ps_rra(stacka, stackb, ps);
		ps_pb(stacka, stackb, ps);
	}
}

t_list	*push_chunks(t_list **stacka, t_list **stackb, t_ps *ps, int chunks)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	set_chunks(ps, chunks);
	while (countnodes(*stacka) > 3)
	{
		// pushbottom(stacka, stackb, ps, i);
		if (*((int *)((*stacka)->content)) <= ps->chunklets[i])
			ps_pb(stacka, stackb, ps);
		else if (*((int *)((*stacka)->content)) <= ps->chunklets[i + 1])
		{
			ps_pb(stacka, stackb, ps);
			ps_rb(stacka, stackb, ps);
		}
		else if ((*stacka)->next != NULL && ++j)
			ps_ra(stacka, stackb, ps);
		if (j == countnodes(*stacka) && i < chunks)
		{
			i = i + 2;
			j = -1;
		}
	}
	return (*stacka);
}
