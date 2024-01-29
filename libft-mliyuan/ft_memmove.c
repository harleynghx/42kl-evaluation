/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:33:59 by mliyuan           #+#    #+#             */
/*   Updated: 2024/01/15 15:48:37 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*lsrc;
	char		*ldst;

	lsrc = (const char *) src;
	ldst = (char *) dest;
	if (lsrc == NULL && ldst == NULL)
		return (NULL);
	if (lsrc < ldst)
	{
		while (n-- > 0)
			ldst[n] = lsrc[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ldst[i] = lsrc[i];
			i++;
		}
	}
	return (ldst);
}
