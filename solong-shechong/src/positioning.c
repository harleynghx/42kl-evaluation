/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:55:44 by shechong          #+#    #+#             */
/*   Updated: 2024/01/25 10:07:42 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	center(t_img *image, t_img *image2)
{
	return (((image->line_length) / 4 - (image2->line_length) / 4) / 2);
}

t_xy	interpolate(t_xy pos, t_xy pos2, int value)
{
	return ((t_xy){(pos.x + (pos2.x - pos.x) / value),
		(pos.y + (pos2.y - pos.y) / value)});
}

t_xy	iso_map(t_xy pos)
{
	return ((t_xy){(pos.x - pos.y) * 1.4, (pos.x + pos.y) / 1.4});
}
