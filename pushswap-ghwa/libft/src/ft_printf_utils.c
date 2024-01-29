/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:10:38 by ghwa              #+#    #+#             */
/*   Updated: 2023/08/09 11:06:45 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_pfputchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_pfputnbr(int n, int i)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}	
	else if (n < 0)
	{
		ft_pfputchar('-');
		n = n * -1;
		i++;
	}
	if (n > 9)
	{
		i = ft_pfputnbr(n / 10, ++i);
	}
	else
		i++;
	ft_pfputchar((n % 10) + '0');
	return (i);
}

int	ft_pfputunbr(unsigned int n, int i)
{
	int	x;

	x = (int)n;
	if (n > 9)
	{
		i = ft_pfputunbr(n / 10, ++i);
	}
	else
		i++;
	ft_pfputchar((n % 10) + '0');
	return (i);
}

int	ft_pfputuintptr(unsigned int num, int x, int i, int c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c == 1)
		hex = "0123456789ABCDEF";
	if (x == 1)
	{
		if (c == 2)
			ft_pfputstr("0x");
		if (num == 0)
		{
			ft_pfputnbr(0, 1);
			return (i + 1);
		}
	}
	if (num != 0)
	{
		i = ft_pfputuintptr(num / 16, 0, ++i, c);
		ft_pfputchar(hex[num % 16]);
	}
	return (i);
}

int	ft_pfputstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_pfstrlen(s)));
}
