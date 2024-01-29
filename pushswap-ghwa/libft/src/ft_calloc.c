/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:22:13 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/06 11:22:13 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	totalsize;
	char	*ptr;
	int		i;

	i = 0;
	if (size == (SIZE_MAX) && nitems == (SIZE_MAX))
		return (NULL);
	else if ((size == 0 && nitems > (SIZE_MAX / 2))
		|| (nitems == 0 && size > (SIZE_MAX / 2)))
		i++;
	else if (size >= (SIZE_MAX / 2) || nitems >= (SIZE_MAX / 2))
		return (NULL);
	totalsize = size * nitems;
	ptr = malloc(totalsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, totalsize);
	return (ptr);
}
