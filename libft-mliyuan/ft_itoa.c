/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 06:08:04 by mliyuan           #+#    #+#             */
/*   Updated: 2024/01/11 15:00:37 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static size_t	ft_signchecker(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static char	*ft_nbr(int n)
{
	int		len;
	int		sign;
	char	*nbrstr;

	len = ft_nbrlen(n);
	sign = ft_signchecker(n);
	nbrstr = malloc(sizeof(char) * (len + 1 + sign));
	if (nbrstr == NULL)
		return (NULL);
	nbrstr[len + sign] = '\0';
	if (n < 0)
		n *= -1;
	while (len--)
	{
		nbrstr[len + sign] = 48 + (n % 10);
		n /= 10;
	}
	if (sign == 1)
		nbrstr[0] = 45;
	return (nbrstr);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == INT_MIN)
	{
		str = malloc(sizeof(char) * 12);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	return (ft_nbr(n));
}
