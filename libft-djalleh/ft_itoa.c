/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:36:31 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/16 18:06:54 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_numlen(int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	len;
	unsigned int	num;

	num = n;
	len = ft_numlen(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		num = num * -1;
	}
	if (num == 0)
		s[0] = '0';
	s[len] = '\0';
	while (num != 0)
	{
		s[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (s);
}
/*
#include <stdio.h>
int main()
{
	printf("%s\n", ft_itoa(83823852));
	return (0);
}*/