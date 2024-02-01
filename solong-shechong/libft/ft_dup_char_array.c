/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_char_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:06:12 by shechong          #+#    #+#             */
/*   Updated: 2024/01/25 11:06:14 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**dup_char_array(char **c)
{
	int		y;
	char	**ret_array;

	y = 0;
	while (c[y])
		y ++;
	ret_array = malloc(sizeof(char *) * (y + 1));
	y = -1;
	while (c[++y])
		ret_array[y] = ft_strdup(c[y]);
	ret_array[y] = NULL;
	return (ret_array);
}
