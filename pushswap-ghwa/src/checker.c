/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:00:33 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/26 16:03:55 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	initall(&ps, argc, argv);
	if (checkinputs(&ps, 1) == 0)
		return (freeall(&stacka, &stackb, &ps));
	initlinkedlist(&ps, &stacka);
	if (getinput(&ps, &stacka, &stackb) == 0)
		return (freeall(&stacka, &stackb, &ps));
	if (stacksorted(&stacka) == 1 || countnodes(stackb) > 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	freeall(&stacka, &stackb, &ps);
}

int	getinput(t_ps *ps, t_list **stacka, t_list **stackb)
{
	char	*temp;

	(void)ps;
	while (1)
	{
		temp = get_next_line(0);
		if (temp == NULL)
			return ((void)free (temp), 1);
		if (checkcmd2(stacka, stackb, ps, temp) == 0 && \
		checkcmd1(stacka, stackb, ps, temp) == 0)
			return ((void)free (temp), error(0));
		free (temp);
	}
	return (1);
}
