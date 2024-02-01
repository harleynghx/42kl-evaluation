/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:33:18 by shechong          #+#    #+#             */
/*   Updated: 2023/04/30 11:33:19 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size ++;
	}
	return (size);
}

static int	getdigit(int num, int index)
{
	while (count_digits(num) > index)
		num /= 10;
	return (num % 10);
}

static char	*checks(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (0);
}

static void	zero(int *n, int *i, char *s)
{
	if (*n < 0)
	{
		s[0] = '-';
		*i = 1;
		*n *= -1;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		i2;
	int		length;

	length = count_digits(n);
	i = 0;
	i2 = 1;
	if (n == 0 || n == -2147483648)
		str = checks(n);
	else
	{
		if (n < 0)
			str = malloc(sizeof(char) * (length + 2));
		else
			str = malloc(sizeof(char) * (length + 1));
		if (!str)
			return (NULL);
		zero (&n, &i, str);
		while (i2 <= length)
			str[i++] = getdigit(n, i2++) + 48;
		str[i] = 0;
	}
	return (str);
}
