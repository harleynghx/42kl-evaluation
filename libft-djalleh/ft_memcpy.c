/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:57:19 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/12 16:26:28 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*memd;
	const char	*mems;
	size_t		i;

	if (n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	i = 0;
	memd = (char *)dst;
	mems = (const char *)src;
	while (i < n)
	{
		memd[i] = mems[i];
		i++;
	}
	return (dst);
}

/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//char *str = NULL;
	//char *str2 = NULL;
	//char *str = "Balls are heavy";
	//char str2[6] = "Fined";

	
	//ft_memcpy(str, str2 ,5);
	//memmove(str + 2, str, 6);
	
	char str[] = "Hello, there are world!";
    //memmove(str + 5, str, 7); 
	memcpy(str + 1, str ,5);
    printf("%s\n", str);


	//printf("%s\n", str);
	//printf("%s\n", str2);
	return (0);
}*/