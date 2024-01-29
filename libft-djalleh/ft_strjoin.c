/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:53:09 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/12 21:17:32 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	m;
	size_t	n;
	size_t	i;
	size_t	j;
	char	*rtn;

	m = ft_strlen(s1);
	n = ft_strlen(s2);
	rtn = (char *)malloc(m + n + 1);
	if (!rtn)
		return (0);
	i = 0;
	j = 0;
	while (s1[j] != 0)
		rtn[i++] = s1[j++];
	j = 0;
	while (s2[j] != 0)
		rtn[i++] = s2[j++];
	rtn[i] = 0;
	return (rtn);
}
