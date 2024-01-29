/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:37:10 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/03 19:03:12 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

/*#include <stdio.h>
int main()
{
	char* string1 = "123456";
	int m = '5';

	printf("%s\n",ft_strrchr(string1,m));
	printf("%d\n",ft_strlen(string1));
	printf("%s\n",string1);
	return (0);
}*/