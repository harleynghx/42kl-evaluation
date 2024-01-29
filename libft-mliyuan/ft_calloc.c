/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:31:58 by mliyuan           #+#    #+#             */
/*   Updated: 2024/01/08 17:08:05 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;

	if (count && size && UINT_MAX / size <= count)
		return (NULL);
	new = malloc(count * size);
	if (new == NULL)
	{
		return (NULL);
	}
	ft_bzero(new, count * size);
	return (new);
}
