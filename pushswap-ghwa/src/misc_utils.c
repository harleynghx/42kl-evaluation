/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:11:52 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/24 12:32:07 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	printlists(t_list *stacka, t_list *stackb)
{
	t_list	*head;

	head = stacka;
	ft_printf("\n\nStack A: ");
	while (head != NULL)
	{
		ft_printf("%d -> ", *((int *)(head->content)));
		head = head->next;
	}
	ft_printf("NULL\n");
	head = stackb;
	ft_printf("Stack B: ");
	while (head != NULL)
	{
		ft_printf("%d -> ", *((int *)(head->content)));
		head = head->next;
	}
	ft_printf("NULL\n\n");
}

int	countnodes(t_list *stack)
{
	int			count;
	t_list		*current;

	count = 0;
	current = stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	*bubblesort(t_ps *ps)
{
	int	i;
	int	j;
	int	*arr;
	int	temp;

	i = 0;
	j = 0;
	arr = ft_dupiarray(ps->iargv, ps->itemcount);
	while (i < ps->itemcount - 1)
	{
		j = 0;
		while (j < ps->itemcount - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	add_ops(char *str, t_ps *ps)
{
	ft_putstr_fd(str, ps->fd);
	ft_putstr_fd(" ", ps->fd);
	return ;
}

void	printsteps(t_ps *ps)
{
	char	*gnl;
	int		i;

	i = 0;
	ps->steps = 0;
	close (ps->fd);
	ps->fd = open("./result", O_RDONLY);
	gnl = get_next_line(ps->fd);
	close (ps->fd);
	while (gnl[i] != '\0')
	{
		if (gnl[i] == ' ')
			ps->steps++;
		i++;
	}
	ft_printf("TOTAL STEPS: %d", ps->steps);
	free (gnl);
}
