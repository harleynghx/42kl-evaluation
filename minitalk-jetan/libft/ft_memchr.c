/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:58:11 by jetan             #+#    #+#             */
/*   Updated: 2023/11/18 01:44:00 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		cha;

	i = 0;
	str = (unsigned char *)s;
	cha = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == cha)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
