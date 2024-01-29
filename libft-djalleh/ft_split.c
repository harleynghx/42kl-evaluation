/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:17:45 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/16 19:43:17 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] != c && s[i] != 0)
				i++;
			if (s[i] == 0)
				return (n);
		}
		i++;
	}
	return (n);
}

static char	**ft_malarr(char **arr, const char *s, char c, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
			len++;
		else if (i > 0 && s[i - 1] != c)
		{
			arr[j] = (char *)malloc(sizeof(char) * (len + 1));
			if (!arr)
				return (0);
			len = 0;
			j++;
		}
		if (s[i + 1] == 0 && s[i] != c)
			arr[j] = (char *)malloc(sizeof(char) * (len + 1));
		i++;
	}
	return (arr);
}

static char	**ft_arrcpy(char **arr, const char *s, char c)
{
	int	a;
	int	i;
	int	j;

	a = 0;
	i = 0;
	j = 0;
	while (s[a] != 0)
	{
		if (s[a] != c)
			arr[i][j++] = s[a];
		else if (a > 0 && s[a - 1] != c)
		{
			arr[i][j] = 0;
			j = 0;
			i++;
		}
		if (s[a + 1] == 0 && s[a] != c)
			arr[i][j] = 0;
		a++;
	}
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	words;

	if (!s)
		return (0);
	words = ft_countwords(s, c);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (0);
	if (words > 0)
	{
		if (!ft_malarr(arr, s, c, 0))
		{
			free(arr);
			return (0);
		}
		ft_arrcpy(arr, s, c);
		if (!arr)
		{
			free(arr);
			return (0);
		}
	}
	arr[words] = (void *)0;
	return (arr);
}
/*
#include <stdio.h>
int main()
{
	char *str = "bbssbsss";
	char **arr;
	char c = 'b';
	int len = ft_countwords(str, c);
	int i = 0;

	arr = ft_split(str, 'b');
	printf("%d\n",ft_countwords(str, c));
	printf("%s\n",str);
	while (i < (len + 1))
		printf("%s\n",arr[i++]);
	return (0);
}*/