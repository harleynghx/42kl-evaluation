/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:05:46 by chenlee           #+#    #+#             */
/*   Updated: 2022/05/05 17:19:06 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char const *s, char c)
{
	char	temp;
	int		i;
	int		j;
	int		strlen;

	temp = c;
	i = 0;
	j = 0;
	strlen = ft_strlen(s);
	while (i < strlen && ft_isascii(s[i]))
	{
		if (temp == c && s[i] != c)
			j++;
		temp = s[i];
		i++;
	}
	return (j);
}

char	*ft_fillptr(char const *s, char c, int i)
{
	int		j;
	int		y;
	char	*ptr;

	j = 0;
	while (s[i + j] && ft_isascii(s[i + j]) && s[i + j] != c)
		j++;
	ptr = malloc(sizeof(char) * (j + 1));
	if (!ptr)
		return (0);
	y = 0;
	while (y < j)
	{
		ptr[y] = s[i];
		y++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**ptrptr;
	char	*ptr;

	ptrptr = malloc(sizeof(char **) * (ft_count(s, c) + 1));
	if (!ptrptr)
		return (0);
	i = 0;
	x = 0;
	while (x < (ft_count(s, c)) && (size_t)i < (ft_strlen(s) + 1)
		&& ft_isascii(s[i]))
	{
		while (s[i] == c)
			i++;
		ptr = ft_fillptr(s, c, i);
		if (ptr == 0)
			return (0);
		ptrptr[x++] = ptr;
		i += ft_strlen(ptr);
	}
	ptrptr[x] = NULL;
	return (ptrptr);
}

// ft_count       - returns total number of strings seperated by deliminator

// ft_fillpointer - fills *ptr with seperated strings
//					first while() loop calculate the length of string
//					second while() loop fills in char in memory allocated ptr

// ft_split	      - malloc ptrptr based on the number of strings separated
//					first while() loop tries to fill in string ptr in ptrptr
//					second while() loop skips deliminator in string s
//					calls in ft_fillpointer to generate seperated-string ptr
//					fill ptrptr with ptr then repeat ptrptr++

// ---------------sorry for my shit explaination---------------