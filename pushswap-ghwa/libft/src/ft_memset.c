/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:19:58 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/21 11:58:39 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memset(void *b, int c, size_t len)
{
	int		ref;
	char	*dest;

	dest = (char *)b;
	ref = 0;
	while ((size_t)ref < len)
	{
		dest[ref] = c;
		ref++;
	}
	return (dest);
}
