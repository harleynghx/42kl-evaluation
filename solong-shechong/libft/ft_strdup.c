/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:50:02 by shechong          #+#    #+#             */
/*   Updated: 2023/04/30 11:50:35 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	return ((char *)ft_memcpy(str, s, (ft_strlen(s) + 1)));
}
