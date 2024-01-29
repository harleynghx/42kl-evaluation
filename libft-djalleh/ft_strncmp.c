/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:40:36 by djalleh           #+#    #+#             */
/*   Updated: 2024/01/09 19:44:22 by djalleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s2[i] != '\0' || s1[i] != '\0') && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/*int main(int ac, char **av)
{
    printf("The argument count %d\n\n",ac);
    printf ("%s\n",av[1]);
    printf ("%s\n",av[2]);
	printf ("Strncmp %d\n",strncmp(av[1],av[2],atoi(av[3])));
	printf ("Mine %d\n",ft_strncmp(av[1],av[2],atoi(av[3])));
	return (0);
*/
