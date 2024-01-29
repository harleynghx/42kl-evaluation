/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:32:09 by ghwa              #+#    #+#             */
/*   Updated: 2023/10/26 15:00:25 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while ((string1[i] == string2[i] && (size_t)i < n - 1)
		&& (string1[i] != '\0' && string2[i] != '\0'))
		i++;
	return (string1[i] - string2[i]);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *s1 = "test.c";
// 	char *s2 = "here_doc";
// 	int	n = 9;

// 	printf("%d", ft_strncmp(s1, s2, n));
// 	return (0);
// }