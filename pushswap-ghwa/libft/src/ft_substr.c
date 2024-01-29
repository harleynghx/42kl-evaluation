/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:23:59 by ghwa              #+#    #+#             */
/*   Updated: 2023/07/07 15:23:59 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		ref;
	int		temp;

	ref = start;
	temp = 0;
	if (!s)
		return (NULL);
	if (len == 0 || (((unsigned int)ft_strlen(s) <= (start)) && (start != 0)))
		return (ft_strdup(""));
	if ((size_t)ft_strlen(s) > len)
		subs = malloc(len + 1);
	else
		subs = malloc(ft_strlen(s) + 1);
	if (!subs)
		return (NULL);
	while ((size_t)temp < len && s[ref] != '\0')
		subs[temp++] = s[ref++];
	subs[temp] = '\0';
	return (subs);
}
// int main(void)
// {
// 	char const *s = "tripouille";
// 	unsigned int start = 0;
// 	size_t len = 42000;
// 	printf("%s", ft_substr(s, start, len));
// 	return (0);
// }