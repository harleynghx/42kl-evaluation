/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:32:26 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/06 10:32:26 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	h;
	int	n;

	h = 0;
	n = 0;
	if (needle[n] == '\0')
		return ((char *)haystack);
	else if (len == 0)
		return (NULL);
	while (needle[n] != '\0' && (size_t)(h + n) < len)
	{
		if (needle[n] == haystack[h + n])
			n++;
		else
		{
			n = 0;
			h++;
		}
		if (haystack[h] == '\0')
			return (NULL);
	}
	if (needle[n] == '\0')
		return ((char *)(haystack + h));
	else
		return (NULL);
}

// int main(void)
// {
// 	char haystack[10] = "bonjourno";
// 	char needle[5] = "n";
// 	char * empty = (char*)"";
// 	printf("%s \n", ft_strnstr(haystack, needle, 2));
// 	return (0);
// }