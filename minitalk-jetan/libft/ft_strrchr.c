/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:45:06 by jetan             #+#    #+#             */
/*   Updated: 2023/11/15 17:35:06 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	find;
	size_t	len;

	last = (char *)s;
	find = (char)c;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (last[len] == find)
			return (last + len);
		len--;
	}
	if (last[len] == find)
		return (last);
	return (NULL);
}
