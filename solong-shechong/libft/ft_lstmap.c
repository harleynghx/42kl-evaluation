/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:43:29 by shechong          #+#    #+#             */
/*   Updated: 2023/04/30 11:43:30 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;
	t_list	*current;

	head = NULL;
	current = lst;
	while (current)
	{
		temp = ft_lstnew(f(current->content));
		if (!temp)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&head, temp);
			current = current->next;
		}
	}
	return (head);
}
