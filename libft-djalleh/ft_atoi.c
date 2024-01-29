/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:27:46 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/12 15:07:22 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	rtn;

	i = 0;
	neg = 1;
	rtn = 0;
	while ((str[i] != '\0') && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		rtn = (rtn * 10) + (str[i] - '0');
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (rtn * neg);
		i++;
	}
	return (rtn);
}

/*#include	<stdlib.h>
#include	<stdio.h>
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("cannot");
		return (0);
	}
	printf("ft_atoi will give %d \n", ft_atoi(av[1]));
	printf("Atoi will give %d \n", atoi(av[1]));
	return (0);
}*/