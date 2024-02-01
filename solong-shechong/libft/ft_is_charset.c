/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:02:41 by shechong          #+#    #+#             */
/*   Updated: 2023/08/21 15:57:48 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_charset(char *str, char *charset)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
			if (str[i] == charset[j])
				break ;
		if (!charset[j])
			return (0);
	}
	return (1);
}
