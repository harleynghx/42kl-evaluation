/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:34:42 by ghwa              #+#    #+#             */
/*   Updated: 2023/09/14 16:42:54 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

char	*ft_gnlstrjoin(char *s1, char *s2)
{
	int		count1;
	int		totalsize;
	int		destcount;
	char	*dest;

	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	if (!s1 && !s2)
		return (NULL);
	count1 = 0;
	totalsize = ft_gnlstrlen(s1) + ft_gnlstrlen(s2);
	destcount = 0;
	dest = malloc(totalsize + 1);
	if (!dest)
		return (NULL);
	while (s1[destcount] != '\0')
		dest[destcount++] = s1[count1++];
	count1 = 0;
	while (s2[count1] != '\0')
		dest[destcount++] = s2[count1++];
	dest[totalsize] = '\0';
	free (s1);
	return (dest);
}

int	ft_gnlstrlen(const char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnlstrdup(const char *s1)
{
	char	*dest;
	int		i;

	dest = malloc(ft_gnlstrlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_gnlstrchr(const char *s, int c)
{
	int				i;
	unsigned char	chrt;

	chrt = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == chrt)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_gnlsubstr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		ref;
	int		temp;

	ref = start;
	temp = 0;
	if (!s)
		return (NULL);
	if (len == 0 || (((unsigned int)ft_gnlstrlen(s) <= (start))
			&& (start != 0)))
		return (ft_gnlstrdup(""));
	if ((size_t)ft_gnlstrlen(s) > len)
		subs = malloc(len + 1);
	else
		subs = malloc(ft_gnlstrlen(s) + 1);
	if (!subs)
		return (NULL);
	while ((size_t)temp < len && s[ref] != '\0')
		subs[temp++] = s[ref++];
	subs[temp] = '\0';
	return (subs);
}
