/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:53:11 by leotan            #+#    #+#             */
/*   Updated: 2024/01/18 18:51:59 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion(char sign, int *count, va_list args)
{
	if (sign == 'c')
		ft_putchar(va_arg(args, int), &*count);
	if (sign == 's')
		ft_putstr(va_arg(args, char *), &*count);
	if (sign == 'p')
		ft_puthex(va_arg(args, unsigned long), &*count, sign);
	if (sign == 'd' || sign == 'i')
		ft_putnbr(va_arg(args, int), &*count);
	if (sign == 'u')
		ft_putnbr(va_arg(args, unsigned int), &*count);
	if (sign == 'x' || sign == 'X')
		ft_puthex(va_arg(args, unsigned int), &*count, sign);
	if (sign == '%')
		ft_putchar('%', &*count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0' && str[i + 1] != '\n')
		{
			ft_conversion(str[++i], &count, args);
			i++;
		}
		else if (str[i] != '%')
		{
			write(1, &str[i++], 1);
			count++;
		}
		else
			i++;
	}
	va_end(args);
	return (count);
}
