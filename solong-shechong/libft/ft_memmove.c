/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:51:27 by shechong          #+#    #+#             */
/*   Updated: 2023/05/06 19:47:10 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (char *)src;
	d = (char *)dest;
	if (!dest && !src)
		return (dest);
	if (s < d)
	{
		while (n--)
			d[n] = s[n];
	}
	else
		return (ft_memcpy(dest, src, n));
	return (d);
}
