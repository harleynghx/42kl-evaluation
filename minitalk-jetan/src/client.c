/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:23:49 by jetan             #+#    #+#             */
/*   Updated: 2024/04/15 15:48:10 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char *str)
{
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		j = 7;
		c = str[i++];
		while (j >= 0)
		{
			if ((c >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j--;
		}
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (-1);
	pid = ft_atoi(av[1]);
	send(pid, av[2]);
	return (0);
}
