/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:29:23 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/21 17:16:27 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*src;
	unsigned char		ch;

	src = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (src[i] == ch)
			return (src + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};
// 	char *a = memchr(s, 2 + 256, 3);
// 	char *t = memchr(s, 2, 0);
// 	char *b = ft_memchr(s, 2 + 256, 3);

// 	/* 5 */ printf("%s\n", a);
// 			printf("%s\n", b);
// 			//printf("%s\n", t);
// 	return (0);
// }
