/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:24:41 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/07 15:24:41 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count1;
	int		count2;
	int		destcount;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	count1 = 0;
	count2 = 0;
	destcount = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (s1[count1] != '\0')
		dest[destcount++] = s1[count1++];
	while (s2[count2] != '\0')
		dest[destcount++] = s2[count2++];
	dest[destcount] = '\0';
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char* s1 = "1234";
// 	char* s2 = "abcd";
// 	printf("%s", ft_strjoin(s1, s2));
// 	return (0);
// }