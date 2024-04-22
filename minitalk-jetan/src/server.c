/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:11:13 by jetan             #+#    #+#             */
/*   Updated: 2024/04/15 17:09:30 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	bit = 7;
	static int	c = 0;

	if (signal == SIGUSR1)
		c += (1 << bit);
	else if (signal == SIGUSR2)
		c += (0 << bit);
	if (bit == 0)
	{
		ft_putchar_fd(c, 1);
		bit = 7;
		c = 0;
	}
	else
		bit--;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (2)
		sleep(1);
	return (0);
}
