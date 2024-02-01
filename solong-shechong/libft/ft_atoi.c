/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:30:36 by shechong          #+#    #+#             */
/*   Updated: 2023/07/03 11:33:06 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkchar(char character)
{
	if (character == ' ' || character == '\f' || character == '\n')
		return (1);
	if (character == '\r' || character == '\t' || character == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	val;
	int	sign;
	int	i;

	i = 0;
	val = 0;
	sign = 1;
	while (checkchar(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		val *= 10;
		val += str[i] - 48;
		i++;
	}
	val *= sign;
	return (val);
}
