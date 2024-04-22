/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:57:07 by nchok             #+#    #+#             */
/*   Updated: 2024/04/18 16:41:56 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bonus_minitalk.h"

void	process(int num, siginfo_t *info)
{
	static int	bit = 7;
	static int	c = 0;

	c += (num << bit);
	if (bit == 0)
	{
		print_char_fd(c, 1);
		bit = 7;
		c = 0;
		kill(info->si_pid, SIGUSR2);
	}
	else
		bit--;
}

void	control(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGUSR1)
		process(1, info);
	else if (signal == SIGUSR2)
	{
		process(0, info);
		(void)context;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	write(1, "Welcome\n", 9);
	write(1, "This program will print out the message you want using client\n",
		63);
	write(1, "Format: ./bonus_client [PID] [Message]\n", 40);
	write(1, "Your Process ID is as below\n", 29);
	print_number(pid);
	write(1, "\n", 1);
	sig.sa_sigaction = control;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
