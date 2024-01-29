/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:24:07 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/07 15:24:07 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	trimstart(const char *set, const char *s1, int setref, int strref)
{
	while (set[setref] != '\0')
	{
		if (set[setref] == s1[strref])
		{
			strref++;
			setref = 0;
		}
		else
			setref++;
	}
	return (strref);
}

int	trimend(const char *set, const char *s1, int setref, int strref)
{
	while (set[setref] != '\0')
	{
		if (set[setref] == s1[strref])
		{
			strref--;
			setref = 0;
		}
		else
			setref++;
	}
	return (strref);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		strref;
	int		setref;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	setref = 0;
	strref = 0;
	start = trimstart(set, s1, setref, strref);
	strref = ft_strlen(s1) - 1;
	end = trimend(set, s1, setref, strref);
	strref = start;
	if ((end - start + 1) < 1)
		return (ft_strdup(""));
	dest = malloc(end - start + 2);
	if (!dest)
		return (NULL);
	while (setref < (end - start + 1))
		dest[setref++] = s1[strref++];
	dest[setref] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	*output = ft_strtrim("   xxxtripouille", " x");
// 	printf("%s\n", output);
// 	return (0);
// }