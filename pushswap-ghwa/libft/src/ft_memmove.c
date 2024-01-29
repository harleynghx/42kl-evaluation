/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:25:02 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/21 11:59:42 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*nsrc;
	char	*ndst;

	nsrc = (char *)src;
	ndst = (char *)dst;
	if (ndst > nsrc)
	{
		i = len + 1;
		while (--i > 0)
			ndst[i - 1] = nsrc[i - 1];
		return ((void *)ndst);
	}
	if (nsrc > ndst)
	{
		i = -1;
		while ((size_t)++i < len)
			ndst[i] = nsrc[i];
		return ((void *)ndst);
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("Hello World");
// 	char s[] = {65, 66, 67, 68, 69, 0, 45};
// 	char s0[] = { 65,  65,  0,  0,  0,  0, 0};
// 	char* p = ft_memmove(s0, s, 7);
// 	printf("%s %s %s", s0, s, p);
// 	return (0);
// }
