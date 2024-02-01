/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:47:00 by shechong          #+#    #+#             */
/*   Updated: 2024/01/25 10:07:42 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ray_init(t_ray *ray, t_xy pos, double angle_deg, int distance)
{
	ray->angle_rad = deg_to_rad(angle_deg);
	ray->end = polar_to_vec2(pos, ray->angle_rad, distance);
	ray->dif = (t_xy){abs(ray->end.x - pos.x), abs(ray->end.y - pos.y)};
	ray->step_x = -1 + ((pos.x < ray->end.x) * 2);
	ray->step_y = -1 + ((pos.y < ray->end.y) * 2);
	ray->error = ray->dif.x - ray->dif.y;
}

int	ray_cast(t_world *world, t_xy pos, double angle_deg, int distance)
{
	t_ray	ray;

	ray_init(&ray, pos, angle_deg, distance);
	while (pos.x != ray.end.x || pos.y != ray.end.y)
	{
		if (pos.x >= 0 && pos.x < world->dimensions.x
			&& pos.y >= 0 && pos.y < world->dimensions.y)
		{
			if (world->tgrid[pos.y][pos.x].type == '1')
				return (0);
			if (pos.x == world->player->pos.x && pos.y == world->player->pos.y)
				return (1);
		}
		if (2 * ray.error > -ray.dif.y)
		{
			ray.error -= ray.dif.y;
			pos.x += ray.step_x;
		}
		if (2 * ray.error < ray.dif.x)
		{
			ray.error += ray.dif.x;
			pos.y += ray.step_y;
		}
	}
	return (0);
}
