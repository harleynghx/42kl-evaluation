/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:03:15 by shechong          #+#    #+#             */
/*   Updated: 2023/09/11 14:41:54 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_stack(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
