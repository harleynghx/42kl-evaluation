/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:07:10 by ghwa              #+#    #+#             */
/*   Updated: 2023/11/07 10:02:45 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_pfstrlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_pfformats(va_list args, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_pfputchar(va_arg(args, int));
	else if (format == 's')
		i += ft_pfputstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		i += ft_pfputnbr(va_arg(args, int), 0);
	else if (format == 'p')
		i += ft_pfputuintptr(va_arg(args, uintptr_t), 1, 2, 2);
	else if (format == 'u')
		i += ft_pfputunbr(va_arg(args, unsigned int), 0);
	else if (format == 'x')
		i += ft_pfputuintptr(va_arg(args, unsigned int), 1, 0, 0);
	else if (format == 'X')
		i += ft_pfputuintptr(va_arg(args, unsigned int), 1, 0, 1);
	else if (format == '%')
		i += ft_pfputchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			ref;
	int			i;

	ref = 0;
	i = 0;
	va_start (args, str);
	if (!str)
		return (0);
	while (str[ref] != '\0')
	{
		if (str[ref] == '%')
		{
			i += ft_pfformats(args, str[ref + 1]);
			ref++;
		}
		else
		{
			ft_pfputchar(str[ref]);
			i++;
		}
		ref++;
	}
	va_end(args);
	return (i);
}
