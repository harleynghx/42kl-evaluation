/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:43:21 by djalleh           #+#    #+#             */
/*   Updated: 2023/11/09 17:48:50 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*mems;
	size_t			i;

	i = 0;
	mems = (unsigned char *)s;
	while (i < n)
	{
		mems[i] = 0;
		i++;
	}
}
