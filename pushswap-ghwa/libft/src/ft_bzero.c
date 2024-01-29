/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:53:29 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/21 11:57:38 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	int				ref;
	unsigned char	*dest;

	dest = (unsigned char *)s;
	ref = 0;
	while ((size_t)ref < n)
	{
		dest[ref] = 0;
		ref++;
	}
	return (dest);
}
