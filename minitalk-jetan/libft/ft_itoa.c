/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:35:49 by jetan             #+#    #+#             */
/*   Updated: 2023/11/17 15:33:27 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countnum(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	size_t	len;

	num = (long)n;
	len = ft_countnum(num);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (num == 0)
		res[0] = '0';
	else if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		res[len--] = (num % 10) + '0';
		num = num / 10;
	}
	return (res);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int numbers[] = {123, -456, 0, 7890, -98765};
//     size_t num_count = sizeof(numbers) / sizeof(numbers[0]);

//     for (size_t i = 0; i < num_count; i++)
//     {
//         char *result = ft_itoa(numbers[i]);
//         if (result)
//         {
//             printf("Number: %d, Result: %s\n", numbers[i], result);
//             free(result);
//         }
//         else
//         {
//             printf("Memory allocation error\n");
//             return 1;
//         }
//     }

//     return 0;
// }
