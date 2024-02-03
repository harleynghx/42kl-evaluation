/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:33:44 by chenlee           #+#    #+#             */
/*   Updated: 2022/04/30 16:28:14 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s_char;

	i = 0;
	s_char = (const char *)s;
	while (i < n)
	{
		if (s_char[i] == (char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
