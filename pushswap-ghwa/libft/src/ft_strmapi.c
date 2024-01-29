/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:23:46 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/21 17:18:55 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		slen;
	char	*dest;
	int		ref;

	if (!s || !f)
		return (NULL);
	ref = 0;
	slen = ft_strlen(s);
	dest = malloc(slen + 1);
	if (!dest)
		return (NULL);
	while (ref < slen)
	{
		dest[ref] = f(ref, s[ref]);
		ref++;
	}
	dest[ref] = '\0';
	return (dest);
}
