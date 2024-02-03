/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:48:30 by chenlee           #+#    #+#             */
/*   Updated: 2022/05/05 16:31:20 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	s1_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1_in_set(s1[start], set))
		start++;
	while (end > start && s1_in_set(s1[end - 1], set))
		end--;
	if (end - start <= 0)
		return (ft_strdup(""));
	else
		ptr = ft_substr(s1, start, ((size_t)end - (size_t)start));
	return (ptr);
}
