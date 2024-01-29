/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:30:04 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/21 13:53:27 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*nsrc;
	char	*ndst;

	if (dst == NULL && src == NULL)
		return (NULL);
	nsrc = (char *)src;
	ndst = (char *)dst;
	i = 0;
	while ((size_t)i < n)
	{
		ndst[i] = nsrc[i];
		i++;
	}
	return (ndst);
}
