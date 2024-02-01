/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:52:25 by shechong          #+#    #+#             */
/*   Updated: 2023/04/30 14:33:45 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = (void *)s;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
		{
			ptr += i;
			return (ptr);
		}
		i ++;
	}
	return (NULL);
}
