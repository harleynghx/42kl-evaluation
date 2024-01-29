/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:05:20 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/22 17:49:26 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

t_list	*ps_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*current;
	t_list	*head;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return (*stack);
	}
	node = *stack;
	current = *stack;
	head = (*stack)->next;
	while ((current)-> next != NULL)
		current = (current)->next;
	(current)->next = node;
	node->next = NULL;
	*stack = head;
	return (*stack);
}

t_list	*ps_ra(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stackb);
	ps_rotate(stacka);
	add_ops("ra", ps);
	ps->steps++;
	return (*stacka);
}

t_list	*ps_rb(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stacka);
	ps_rotate(stackb);
	add_ops("rb", ps);
	ps->steps++;
	return (*stackb);
}

void	ps_rr(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_rotate(stacka);
	ps_rotate(stackb);
	add_ops("rr", ps);
	ps->steps++;
	return ;
}
