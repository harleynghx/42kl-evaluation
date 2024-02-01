/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:53:09 by shechong          #+#    #+#             */
/*   Updated: 2023/04/30 11:53:10 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set_char(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && is_set_char(s1[start], set))
		start ++;
	while (end > start && is_set_char(s1[end], set))
		end --;
	trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}
