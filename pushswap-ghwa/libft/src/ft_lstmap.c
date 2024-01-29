/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:11:14 by ghwa              #+#    #+#             */
/*   Updated: 2023/11/28 20:21:52 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_lstcheck(t_list *new_node)
{
	if (!new_node)
		return (0);
	else
		return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		if (new_list == NULL)
		{
			new_node = ft_lstnew(f(lst->content));
			new_list = new_node;
		}
		else
		{
			temp = ft_lstnew(f(lst->content));
			new_node->next = temp;
			new_node = new_node->next;
		}
		if (new_node == NULL)
			ft_lstclear(&new_list, (*del));
		lst = lst->next;
	}
	return (new_list);
}
