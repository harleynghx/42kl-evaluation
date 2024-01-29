/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:17:34 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/25 01:08:02 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

int	checknumber(t_ps *ps)
{
	int	i;

	i = 1;
	if (ps->argc < 1)
		return (0);
	while (ps->argv[i] != NULL)
	{
		if (ft_isdigitarray(ps->argv) == 0)
		{
			return (error(0));
		}
		if (ft_atoi(ps->argv[i]) == 0 && ft_strncmp(ps->argv[i], "0", \
		ft_strlen(ps->argv[i])) != 0)
			return (error(0));
		if (ft_atol(ps->argv[i]) > 2147483647 \
		|| ft_atol(ps->argv[i]) < -2147483648)
			return (error(0));
		ps->iargv[i - 1] = ft_atoi(ps->argv[i]);
		i++;
	}
	return (1);
}

int	checkrepeat(t_ps *ps)
{
	int	anchor;
	int	count;
	int	head;

	head = 0;
	while (head < ps->itemcount)
	{
		count = head;
		anchor = ps->iargv[head];
		while (++count < ps->itemcount)
		{
			if (anchor == ps->iargv[count])
				return (error(0));
		}
		head++;
	}
	return (1);
}

int	checksorted(t_ps *ps)
{
	int	count;

	count = 0;
	while (count < ps->itemcount - 1)
	{
		if (ps->iargv[count] >= ps->iargv[count + 1])
			return (1);
		count++;
	}
	return (0);
}

int	checkinputs(t_ps *ps, int code)
{
	if (ps->argv[1] == NULL)
		return (0);
	if (checknumber(ps) == 0)
		return (0);
	if (checkrepeat(ps) == 0)
		return (0);
	if (checksorted(ps) == 0 && code == 0)
		return (0);
	return (1);
}
