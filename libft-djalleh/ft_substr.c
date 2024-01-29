/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:16:09 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/12 20:50:08 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	rtn = malloc(len + 1);
	if (!rtn)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			rtn[j] = s[i];
			j++;
		}
		i++;
	}
	rtn[j] = 0;
	return (rtn);
}

/*#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	printf ("%d \n", ft_strlen(av[1]));
	printf ("%s \n", ft_substr(av[1],5,5));
	return (0);
}*/