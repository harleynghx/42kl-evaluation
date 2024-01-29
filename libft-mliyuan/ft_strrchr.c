/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:36:04 by mliyuan           #+#    #+#             */
/*   Updated: 2024/01/12 17:40:58 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char const	*tmp;

	tmp = NULL;
	while (*str)
	{
		if (*str == (char)c)
			tmp = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return ((char *)tmp);
}
