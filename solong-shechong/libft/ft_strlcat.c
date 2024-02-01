/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:50:25 by shechong          #+#    #+#             */
/*   Updated: 2023/05/03 13:11:05 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;

	destlen = 0;
	while (destlen < size && dst[destlen])
		destlen ++;
	i = 0;
	while (src[i] && (i + destlen + 1) < size)
	{
		dst[i + destlen] = src[i];
		i++;
	}
	if (destlen < size)
		dst[i + destlen] = '\0';
	return (destlen + ft_strlen(src));
}
