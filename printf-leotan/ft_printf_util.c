/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:55:49 by leotan            #+#    #+#             */
/*   Updated: 2024/01/18 18:52:41 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (!(str))
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	*count += i;
}

void	ft_puthex(unsigned long decimal, int *count, char sign)
{
	if (decimal > 15)
		ft_puthex(decimal / 16, &*count, sign);
	else if (sign == 'p')
	{
		write(1, "0x", 2);
		*count += 2;
	}
	if (sign == 'p' || sign == 'x')
		write(1, &"0123456789abcdef"[decimal % 16], 1);
	else if (sign == 'X')
		write(1, &"0123456789ABCDEF"[decimal % 16], 1);
	(*count)++;
}

void	ft_putnbr(long n, int *count)
{
	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, &*count);
	write(1, &"0123456789"[n % 10], 1);
	(*count)++;
}
