/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:25:14 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/24 23:56:21 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

t_list	*ps_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return (*stack);
	}
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (*stack);
}

t_list	*ps_sa(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stackb);
	ps_swap(stacka);
	add_ops("sa", ps);
	ps->steps++;
	return (*stacka);
}

t_list	*ps_sb(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stacka);
	ps_swap(stackb);
	add_ops("sb", ps);
	ps->steps++;
	return (*stackb);
}

void	ps_ss(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_swap(stacka);
	ps_swap(stackb);
	add_ops("ss", ps);
	ps->steps++;
	return ;
}
