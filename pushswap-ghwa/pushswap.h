/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:05:21 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/26 16:30:29 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/inc/libft.h"

typedef struct s_ps
{
	int		argc;
	char	**argv;
	int		*iargv;
	int		itemcount;
	int		*chunklets;
	int		steps;
	char	**ops;
	int		fd;
	char	*input;
}	t_ps;

int		initall(t_ps *ps, int argc, char **argv);
int		checkinputs(t_ps *ps, int code);
void	initlinkedlist(t_ps *ps, t_list **stacka);
int		error(int code);
void	printlists(t_list *stacka, t_list *stackb);
t_list	*push_chunks(t_list **stacka, t_list **stackb, t_ps *ps, int chunks);
int		*bubblesort(t_ps *ps);
int		countnodes(t_list *stack);
void	add_ops(char *str, t_ps *ps);
void	smallsort(t_ps *ps, t_list **stacka, t_list **stackb);
void	threesort(t_list **stacka, t_list **stackb, t_ps *ps);
void	fivesort(t_list **stacka, t_list **stackb, t_ps *ps);
int		stacksorted(t_list **stack);
int		freeall(t_list **stacka, t_list**stackb, t_ps *ps);
void	pushback(t_list **stacka, t_list **stackb, t_ps *ps, int pos);
void	pushintopos(t_list **stacka, t_list **stackb, t_ps *ps, int pos);
int		findpos(t_list **stacka, t_list **stackb, int code);
int		countpos(t_list **stacka, t_list *lowest, int code);
void	bigsort(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*largestmodule(t_list *stack);
void	optops(t_ps *ps);
void	printsteps(t_ps *ps);

int		getinput(t_ps *ps, t_list **stacka, t_list **stackb);
int		checkcmd1(t_list **stacka, t_list **stackb, t_ps *ps, char *cmd);
int		checkcmd2(t_list **stacka, t_list **stackb, t_ps *ps, char *cmd);

void	ps_donothing(t_list **stack);
t_list	*ps_swap(t_list **stack);
t_list	*ps_sa(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_sb(t_list **stacka, t_list **stackb, t_ps *ps);
void	ps_ss(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_push(t_list **stacki, t_list **stacko);
t_list	*ps_pa(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_pb(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_rotate(t_list **stack);
t_list	*ps_ra(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_rb(t_list **stacka, t_list **stackb, t_ps *ps);
void	ps_rr(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_reverse_rotate(t_list **stack);
t_list	*ps_rra(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_rrb(t_list **stacka, t_list **stackb, t_ps *ps);
void	ps_rrr(t_list **stacka, t_list **stackb, t_ps *ps);
#endif