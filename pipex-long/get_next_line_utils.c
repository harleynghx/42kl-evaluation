/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:59:55 by long              #+#    #+#             */
/*   Updated: 2023/11/06 23:07:50 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst && new)
	{
		if (*lst)
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
		else
			*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	make_new(t_list **bufstr, char *str)
{
	t_list	*new;
	t_list	*tmp;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->str = str;
	new->next = NULL;
	while (*bufstr)
	{
		tmp = (*bufstr)->next;
		free((*bufstr)->str);
		free(*bufstr);
		*bufstr = tmp;
	}
	if (*str)
		*bufstr = new;
	else
	{
		free(str);
		free(new);
	}
}

void	clean_list(t_list **bufstr)
{
	int		i;
	int		k;
	t_list	*tmp;
	char	*str;

	if (!bufstr || !*bufstr)
		return ;
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return ;
	tmp = ft_lstlast(*bufstr);
	i = -1;
	k = 0;
	while (tmp->str[++i])
	{
		if (tmp->str[i] == '\n')
			break ;
	}
	while (tmp->str[i++])
		str[k++] = tmp->str[i];
	str[k] = 0;
	make_new(bufstr, str);
}
