/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:56:28 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/12 13:25:24 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	chrt;

	chrt = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == chrt)
			return ((char *)s + i);
		i++;
	}
	if (chrt == '\0')
		return ((char *)s + i);
	else
		return (NULL);
}
