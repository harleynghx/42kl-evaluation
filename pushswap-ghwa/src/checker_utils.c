/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:20:03 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/26 16:03:19 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"


int	checkcmd1(t_list **stacka, t_list **stackb, t_ps *ps, char *cmd)
{
	if (ft_strncmp(cmd, "pa", 2) == 0)
		ps_pa(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		ps_pb(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		ps_ra(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		ps_rb(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		ps_rr(stacka, stackb, ps);
	else
		return (0);
	return (1);
}

int	checkcmd2(t_list **stacka, t_list **stackb, t_ps *ps, char *cmd)
{
	if (ft_strncmp(cmd, "rra", 3) == 0)
		ps_rra(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		ps_rrb(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
		ps_rrr(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "sa", 2) == 0)
		ps_sa(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		ps_sb(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "ss", 2) == 0)
		ps_ss(stacka, stackb, ps);
	else
		return (0);
	return (1);
}
