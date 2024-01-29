/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:54:03 by ghwa              #+#    #+#             */
/*   Updated: 2023/11/28 20:18:55 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*nextn;

	if (!lst || !del)
		return ;
	current = (*lst);
	while (current != NULL)
	{
		nextn = current->next;
		del(current->content);
		free(current);
		current = nextn;
	}
	*lst = NULL;
}
