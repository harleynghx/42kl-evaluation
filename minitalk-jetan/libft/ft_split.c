/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:24:16 by jetan             #+#    #+#             */
/*   Updated: 2024/03/12 18:07:55 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_wordlen(char const *s, char c, size_t start)
{
	size_t	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res[j] = ft_substr(s, i, ft_wordlen(s, c, i));
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char **result;	
// 	result = ft_split("IM TIRED    BLEH", ' ');
// 	printf("%s", result[5]);
// }
