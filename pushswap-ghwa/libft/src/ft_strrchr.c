/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:07:19 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/21 11:55:55 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = ft_strlen(s);
	while (s[i] != cc && i > 0)
		i--;
	if (s[i] == cc)
		return ((char *)s + i);
	else if (cc == '\0')
		return ((char *)s + ft_strlen(s));
	else
		return (NULL);
}
