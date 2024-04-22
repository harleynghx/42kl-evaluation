/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:56:36 by nchok             #+#    #+#             */
/*   Updated: 2024/04/18 15:16:58 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	send(int pid, char *str)
{
	int				i;
	int				bit;
	unsigned char	c;
	unsigned char	shifted;
	unsigned char	cleansed;

	i = 0;
	c = 0;
	while (str[i])
	{
		bit = 7;
		c = str[i++];
		while (bit >= 0)
		{
			shifted = c >> bit;
			cleansed = shifted & 1;
			if (cleansed == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			bit--;
		}
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send(pid, av[2]);
		send(pid, "\n");
	}
	else
	{
		write(1, "Wrong format\n", 14);
		write(1, "Please try again with format below\n", 22);
		write(1, "./client [PID] [MESSAGE]\n", 32);
	}
	return (0);
}
