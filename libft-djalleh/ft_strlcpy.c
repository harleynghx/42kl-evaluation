/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:52:44 by djalleh           #+#    #+#             */
/*   Updated: 2023/11/21 20:53:04 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j] != 0)
	{
		j++;
	}
	if (n == 0)
		return (j);
	while ((i < (n - 1)) && (src[i] != 0))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
	char dst1[] = "hello";
	char src1[] = "byebyebirdie";
	char dst2[] = "hello";
	char src2[] = "byebyebirdie";
	size_t a;
	size_t b;

	a = strlcpy(dst1, src1, 3);
	b = ft_strlcpy(dst2, src2, 3);

	printf("strlcpy answer is %s \n", dst1);
	printf("ft_strlcpy answer is %s \n", dst2);
	printf("strlcpy return is %zu \n", a);
	printf("ft_strlcpy return is %zu \n", b);

	return (0);
}*/