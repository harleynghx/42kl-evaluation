/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:34:57 by djalleh           #+#    #+#             */
/*   Updated: 2023/11/09 21:27:52 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mems;
	size_t			i;

	i = 0;
	mems = (unsigned char *)s;
	while (i < n)
	{
		mems[i] = c;
		i++;
	}
	return (s);
}

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//char *str = NULL;
	//char *str2 = NULL;
	char str[5];
	char str2[5];

	memset(str2, 'a' ,5);
	ft_memset(str, 'a' ,5);

	str[4] = '\0';
	str2[4] = '\0';

	printf("%s\n", str);
	printf("%s\n", str2);
	return (0);
}*/