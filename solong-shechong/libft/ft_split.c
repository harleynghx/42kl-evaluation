/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:38:38 by shechong          #+#    #+#             */
/*   Updated: 2023/04/30 11:40:40 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_items(const char *s, char sep)
{
	int	start;
	int	size;

	size = 0;
	start = 0;
	while (s[start])
	{
		while (s[start] == sep)
			start++;
		if (s[start])
			size ++;
		while (s[start] && s[start] != sep)
			start++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	int		end;
	int		array_i;
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(str) * (count_items(s, c) + 1));
	if (!str)
		return (NULL);
	array_i = 0;
	start = 0;
	end = 0;
	while (s[start] && s[end])
	{
		while (s[start] == c && s[start++])
			end++;
		while (s[end] != c && s[end])
			end++;
		if (s[end] || (!s[end] && start != end))
			str[array_i++] = ft_substr(s, start, end - start);
		start = end;
	}
	str[array_i] = (void *)0;
	return (str);
}
