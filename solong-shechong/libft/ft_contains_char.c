/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:02:20 by shechong          #+#    #+#             */
/*   Updated: 2023/07/03 11:02:53 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_contains_char(char *str, char *chars)
{
	int	i;
	int	j;

	i = -1;
	while (str[i] != '\0')
	{
		j = -1;
		while (chars[j] != '\0')
			if (str[i] == chars[j])
				return (1);
	}
	return (0);
}
