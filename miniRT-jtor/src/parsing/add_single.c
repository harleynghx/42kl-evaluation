/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_single.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:03:13 by jthor             #+#    #+#             */
/*   Updated: 2024/02/03 14:09:29 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	add_ambience(t_amb *obj, char **arr)
{
	if (obj->flag == 1)
		return (3);
	if (ft_arrlen(arr) != 3)
		return (2);
	obj->ratio = assign_ratio(&(obj->flag), arr[1]);
	assign_rgb(&(obj->flag), &(obj->colour), arr[2]);
	if (obj->flag == -1)
		return (2);
	obj->flag = 1;
	return (0);
}

void	get_up_right(t_cam *camera, t_coord rot_axis, int first_time, int bruh)
{
	if (first_time)
	{
		camera->up = normalize(rot_axis);
		if (camera->up.y < 0.0001)
			camera->up = vect_mult(camera->up, -1);
		camera->right = cross_prod(camera->up, camera->look);
	}
	else
	{
		if (bruh == 1)
			camera->right = cross_prod(camera->up, camera->look);
		else
			camera->up = cross_prod(camera->look, camera->right);
	}
}

void	calc_camera_orientation(t_cam *camera, int first_time, int axis)
{
	t_coord	world_coord[3];
	t_coord	rot_axis;

	set_coord(&world_coord[0], 1, 0, 0);
	set_coord(&world_coord[1], 0, 1, 0);
	set_coord(&world_coord[2], 0, 0, 1);
	rot_axis = cross_prod(world_coord[2], camera->look);
	if (is_zero_vector(rot_axis))
	{
		if (camera->look.z <= -0.0001)
			camera->right = vect_mult(world_coord[0], -1.0);
		else
			camera->right = world_coord[0];
		camera->up = world_coord[1];
	}
	else
		get_up_right(camera, rot_axis, first_time, axis);
}

int	add_camera(t_cam *obj, char **arr)
{
	if (obj->flag == 1)
		return (3);
	if (ft_arrlen(arr) != 4)
		return (2);
	assign_coord(&(obj->flag), &(obj->point), arr[1]);
	assign_vector(&(obj->flag), &(obj->look), arr[2]);
	obj->fov = assign_fov(&(obj->flag), arr[3]);
	if (obj->flag == -1)
		return (2);
	calc_camera_orientation(obj, 1, 0);
	obj->flag = 1;
	return (0);
}

int	add_light(t_light *obj, char **arr)
{
	if (obj->flag == 1)
		return (3);
	if (ft_arrlen(arr) != 4)
		return (2);
	assign_coord(&(obj->flag), &(obj->point), arr[1]);
	obj->ratio = assign_ratio(&(obj->flag), arr[2]);
	assign_rgb(&(obj->flag), &(obj->colour), arr[3]);
	if (obj->flag == -1)
		return (2);
	obj->flag = 1;
	return (0);
}
