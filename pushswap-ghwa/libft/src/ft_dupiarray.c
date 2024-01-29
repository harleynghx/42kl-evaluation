/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupiarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:07:49 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/07 16:19:26 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_dupiarray(const int *sourcearray, size_t size)
{
	int	*newarray;

	if (sourcearray == NULL || size == 0)
	{
		return (NULL);
	}
	newarray = (int *)malloc(size * sizeof(int));
	if (newarray == NULL)
	{
		return (NULL);
	}
	ft_memcpy(newarray, sourcearray, size * sizeof(int));
	return (newarray);
}
