/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:20:56 by jetan             #+#    #+#             */
/*   Updated: 2023/11/17 16:53:28 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*savenode;
	t_list	*newlist;
	t_list	*newnode;

	savenode = lst;
	newlist = NULL;
	while (savenode)
	{
		newnode = ft_lstnew(f(savenode->content));
		if (newnode == NULL)
		{
			ft_lstclear(&newlist, del);
			return ((void *)(0));
		}
		ft_lstadd_back(&newlist, newnode);
		savenode = savenode->next;
	}
	newnode = NULL;
	return (newlist);
}
