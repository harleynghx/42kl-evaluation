/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:10:40 by shechong          #+#    #+#             */
/*   Updated: 2023/07/18 16:11:28 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*f(void *ptr, void *input)
{
	free(ptr);
	return (input);
}

void	*fa(void **ptr, void *input)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i ++;
	}
	free(ptr);
	return (input);
}
