/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:57:19 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/12 16:33:24 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*memd;
	unsigned char	*mems;
	size_t			i;

	if (n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	i = 0;
	memd = (unsigned char *)dst;
	mems = (unsigned char *)src;
	if (dst > src)
	{
		while (n > 0)
		{
			n--;
			memd[n] = mems[n];
		}
	}
	while (i < n)
	{
		memd[i] = mems[i];
		i++;
	}
	return (dst);
}

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//char *str = NULL;
	//char *str2 = NULL;
	//char *str = "Balls are heavy";
	//char str2[6] = "Fined";

	//memcpy(str, str2 ,5);
	//ft_memcpy(str, str2 ,5);
	//memmove(str + 2, str, 6);
	
	char str[] = "Hello, world!";
    //ft_memmove(str + 7, str, 7); 
	memmove(str + 6, str, 7); 
    printf("%s\n", str); // Output: "world!Hello"

    return 0;

	//printf("%s\n", str);
	//printf("%s\n", str2);
	return (0);
}*/