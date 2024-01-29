/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:30:26 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/12 16:34:20 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	len;
	size_t	olen;

	len = 0;
	i = 0;
	while (len < dstsize && dst[len] != '\0')
		len++;
	olen = len;
	while (len < dstsize - 1 && dstsize != 0 && src[i] != '\0')
	{
		dst[len] = src[i];
		len++;
		i++;
	}
	if (dstsize > 0 && dstsize > olen)
		dst[len] = '\0';
	return (olen + ft_strlen(src));
}

// int	main(void)
// {
// 	char dest[30];
// 	memset(dest, 0, 30);
// 	char *src = (char *)"AAAAAAAAA"; // 9
// 	memset(dest, 'C', 5);
// 	printf("%zu \n", ft_strlcat(dest, src, -1));
// 	printf("%s", dest);
// 	return (0);
// }
