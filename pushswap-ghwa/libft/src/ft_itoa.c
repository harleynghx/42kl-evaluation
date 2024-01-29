/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:48:30 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/21 17:17:57 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_itoasub(int n, int len, char *array)
{
	int	i;

	if (n < 0)
	{
		n *= -1;
		len++;
		array = malloc(len + 1);
		if (!array)
			return (NULL);
		array[0] = '-';
	}
	else
		array = malloc(len + 1);
	if (!array)
		return (NULL);
	i = len - 1;
	while (n > 0)
	{
		array[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	array[len] = '\0';
	return (array);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		i;
	int		len;

	array = NULL;
	len = 0;
	i = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	while (i != 0)
	{
		len++;
		i = i / 10;
	}
	array = ft_itoasub(n, len, array);
	if (!array)
		return (NULL);
	return (array);
}

// int	main(void)
// {
// 	int	i = 10;

// 	printf("%s\n", ft_itoa(i));
// 	return (0);
// }