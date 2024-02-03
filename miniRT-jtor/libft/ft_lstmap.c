/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:55:51 by chenlee           #+#    #+#             */
/*   Updated: 2022/05/10 16:55:51 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	newlst = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			while (newlst)
			{
				temp = newlst->next;
				(*del)(newlst->content);
				free(newlst);
				newlst = temp;
			}
			lst = NULL;
			return (0);
		}
		ft_lstadd_back(&newlst, temp);
		lst = lst->next;
	}
	return (newlst);
}

// {
// 	t_list	*new_lst;
// 	t_list	*temp;

// 	if (!lst || !f || !del)
// 		return (0);
// 	new_lst = NULL;
// 	while (lst)
// 	{
// 		new_lst = ft_lstnew(f(lst->content));
// 		if (!new_lst)
// 		{
// 			while (head)
// 			{
// 				new_lst = head->next;
// 				(del)(head->content);
// 				free(head);
// 				head = new_lst;
// 			}
// 			lst = NULL;
// 			return (0);
// 		}
// 		else
// 			ft_lstadd_back(&head, new_lst);
// 		lst = lst->next;
// 	}
// 	new_lst->next = 0;
// 	return (new_lst);
// }
