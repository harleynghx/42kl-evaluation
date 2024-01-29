/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:55:50 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/03 15:14:45 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while ((i < n) && dst[i] != 0)
		i++;
	while (((i + j + 1) < n) && (src[j] != 0))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < n)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char dst1[20] = "hello";
	char src1[] = "byebyebirdie";
	char dst2[20] = "hello";
	char src2[] = "byebyebirdie";
	size_t a;
	size_t b;

	a = strlcat(dst1, src1, 7);
	b = ft_strlcat(dst2, src2, 7);

	printf("strlcat answer is %s \n", dst1);
	printf("ft_strlcat answer is %s \n", dst2);
	printf("strlcat return is %zu \n", a);
	printf("ft_strlcat return is %zu \n", b);

	return (0);
}*/