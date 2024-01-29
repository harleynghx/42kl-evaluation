/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:34:27 by mliyuan           #+#    #+#             */
/*   Updated: 2024/01/17 13:06:49 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strlalloc(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	deslen;
	size_t	srclen;

	if ((dest == NULL || src == NULL) && size == 0)
		return (0);
	deslen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size == 0 || size < deslen)
		return (srclen + size);
	ft_strlalloc(dest, src, size);
	return (deslen + srclen);
}
