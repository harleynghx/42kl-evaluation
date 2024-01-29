/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:24:14 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/07 15:24:14 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	substrlen(char const *s, char c, int pos)
{
	int	len;

	len = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] != c)
		{
			len++;
			pos++;
		}
		else
			return (len);
	}
	return (len);
}

int	ft_howmanystrings(char const *s, char c)
{
	int	i;
	int	numstr;

	if (s[0] == '\0')
		return (1);
	i = 0;
	numstr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i + 1] != '\0')
				i++;
			numstr++;
			i++;
		}
	}
	return (numstr);
}

char	*ft_split2(char const *s, int c, int pos, int sref)
{
	char	*arr;
	int		len;

	len = substrlen(s, c, pos);
	if (len < 1)
		return (NULL);
	arr = malloc(len + 1);
	while (len > 0)
	{
		arr[sref] = s[pos];
		sref++;
		pos++;
		len--;
	}
	arr[sref] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		aref;
	int		sref;
	int		pos;

	aref = 0;
	pos = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc((ft_howmanystrings(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[pos] != '\0')
	{
		if (s[pos] == c)
			pos++;
		else if (s[pos] != c && aref < (ft_howmanystrings(s, c) + 1))
		{
			sref = 0;
			arr[aref++] = ft_split2(s, c, pos, sref);
			pos += substrlen(s, c, pos);
		}
	}
	arr[aref] = NULL;
	return (arr);
}

// int	main (void)
// {
// 	int i = 0;
// 	int j = 0;
// 	char *string = "poopapoop";
// 	char sep = 'a';
// 	char **dest = ft_split(string, sep);
// 	while (dest[i])
// 	{
// 		j = 0;
// 		while (dest[i][j])
// 		{
// 			printf("%c", dest[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	return (0);
// }