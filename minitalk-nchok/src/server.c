/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:06:11 by nchok             #+#    #+#             */
/*   Updated: 2024/04/18 16:42:13 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	process(int num)
{
	static int	bit = 7;
	static int	c = 0;

	c += (num << bit);
	if (bit == 0)
	{
		print_char_fd(c, 1);
		bit = 7;
		c = 0;
	}
	else
		bit--;
}

void	control(int signal)
{
	if (signal == SIGUSR1)
		process(1);
	else if (signal == SIGUSR2)
		process(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "Welcome\n", 9);
	write(1, "This program will print out the message you want using client\n",
		63);
	write(1, "Format: ./client [PID] [Message]\n", 34);
	write(1, "Your Process ID is as below\n", 29);
	print_number(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, control);
	signal(SIGUSR2, control);
	while (1)
		pause();
	return (0);
}
