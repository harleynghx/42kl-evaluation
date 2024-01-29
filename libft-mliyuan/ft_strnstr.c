/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:31:28 by mliyuan           #+#    #+#             */
/*   Updated: 2024/01/16 14:59:25 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hl;
	size_t	nl;

	hl = 0;
	nl = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[hl] && hl < len)
	{
		if (haystack[hl] == needle[nl])
		{
			while ((haystack[hl + nl] == needle[nl]
					&& haystack[hl + nl] != '\0')
				&& hl + nl < len)
				nl++;
			if (needle[nl] == '\0')
				return ((char *) haystack + hl);
		}
		hl++;
		nl = 0;
	}
	return (NULL);
}
