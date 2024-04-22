/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:32:03 by nchok             #+#    #+#             */
/*   Updated: 2024/04/18 16:40:04 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bonus_minitalk.h"

static void	confirm(int signal)
{
	if (signal == SIGUSR1)
		write(1, "OH NO!\n", 8);
	else
		write(1, "Successfully sent\n", 19);
}

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
	int					pid;
	int					i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, confirm);
		signal(SIGUSR2, confirm);
		send(pid, av[2]);
		send(pid, "\n");
	}
	else
	{
		write(1, "Wrong format\n", 14);
		write(1, "Please try again with format below\n", 22);
		write(1, "./client_bonus [PID] [MESSAGE]\n", 32);
	}
	return (0);
}
