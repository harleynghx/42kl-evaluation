/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:08:57 by nchok             #+#    #+#             */
/*   Updated: 2024/04/17 01:07:51 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	results;

	sign = 1;
	results = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str == '+' || *str == '-')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		results *= 10;
		results += (*str) - '0';
		str++;
	}
	return (results * sign);
}

void	print_number(int num)
{
	char	*numstr;
	char	digit;

	numstr = "0123456789";
	if (num >= 10)
		print_number(num / 10);
	digit = numstr[num % 10];
	write(1, &digit, 1);
}

void	print_char_fd(char c, int fd)
{
	write(fd, &c, 1);
}
