/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:13:44 by chenlee           #+#    #+#             */
/*   Updated: 2022/04/30 16:23:25 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*srce;

	i = 0;
	dest = (char *)dst;
	srce = (char *)src;
	if (dst == src)
		return (dst);
	if (dest > srce)
	{
		while (len--)
			dest[len] = srce[len];
		return (dst);
	}
	while (i < len)
	{
		dest[i] = srce[i];
		i++;
	}
	return (dst);
}
