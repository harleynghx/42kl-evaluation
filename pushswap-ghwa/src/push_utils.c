/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:13:40 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/24 12:25:29 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ps_donothing(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (head == NULL)
		return ;
	if (head->next != NULL)
		head = head->next;
	return ;
}

t_list	*largestmodule(t_list *stack)
{
	t_list	*largest;
	t_list	*stack2;

	largest = stack;
	stack2 = stack;
	while (stack2 != NULL)
	{
		if (*(int *)largest->content < *(int *)stack2->content)
			largest = stack2;
		stack2 = stack2->next;
	}
	return (largest);
}
