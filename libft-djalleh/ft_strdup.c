/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:46:07 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/12 20:00:58 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	n;

	n = ft_strlen(s1) + 1;
	str = (char *)malloc(n);
	if (!str)
		return (0);
	str = ft_memcpy(str, s1, n);
	return (str);
}
