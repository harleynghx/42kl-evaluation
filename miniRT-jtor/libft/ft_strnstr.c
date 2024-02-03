/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:17:58 by chenlee           #+#    #+#             */
/*   Updated: 2022/04/30 18:37:44 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while ((big[i + j] == little[j]) && ((i + j) < len))
		{
			if ((!big[i + j]) && (!little[j]))
				return ((char *)&big[i]);
			j++;
		}
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (0);
}
