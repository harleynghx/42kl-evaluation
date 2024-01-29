/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:32:09 by ghwa              #+#    #+#             */
/*   Updated: 2023/10/11 10:44:15 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strendcmp(const char *s1, const char *s2)
{
	int				i;
	int				j;
	unsigned char	*string1;
	unsigned char	*string2;

	i = 0;
	j = 0;
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (string1[i] != '\0')
		i++;
	while (string2[j] != '\0')
		j++;
	i--;
	j--;
	while (string1[i] == string2[j])
	{	
		if (j == 0)
			return (1);
		i--;
		j--;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s1 = "2212";
// 	char *s2 = "22212";

// 	printf("%d", ft_strendcmp(s1, s2));
// 	return (0);
// }
