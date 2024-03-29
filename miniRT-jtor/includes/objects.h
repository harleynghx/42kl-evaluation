/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:10:36 by jthor             #+#    #+#             */
/*   Updated: 2024/01/30 17:10:39 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

enum e_index
{
	sp,
	pl,
	cy,
	co
};

enum e_arr_idx
{
	ori = 0,
	vec = 1
};

enum e_rt_rays
{
	to_light = 0,
	to_viewer = 1,
	normal = 2,
	reflect_dir = 3,
	from_camera = 4
};

typedef struct s_rgb
{
	double	red;
	double	green;
	double	blue;
}	t_rgb;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_coord;

typedef struct s_amb
{
	int		flag;
	double	ratio;
	t_rgb	colour;
}	t_amb;

typedef struct s_cam
{
	int		flag;
	t_coord	point;
	t_coord	look;
	t_coord	up;
	t_coord	right;
	double	fov;
}	t_cam;

typedef struct s_light
{
	int		flag;
	t_coord	point;
	double	ratio;
	t_rgb	colour;
}	t_light;

typedef struct s_co
{
	int		flag;
	t_coord	vertex;
	t_coord	axis_vector;
	t_coord	base_center;
	double	radius;
	double	height;
	t_rgb	colour;
	t_coord	intsct;
	int		intsct_type;
}	t_co;

typedef struct s_sp
{
	int		flag;
	t_coord	center;
	double	dia;
	t_rgb	colour;
	t_coord	intsct;
}	t_sp;

typedef struct s_pl
{
	int		flag;
	t_coord	point;
	t_coord	normal_vector;
	t_rgb	colour;
	t_coord	intsct;
}	t_pl;

typedef struct s_cy
{
	int		flag;
	t_coord	center;
	t_coord	axis_vector;
	double	radius;
	double	height;
	t_rgb	colour;
	t_coord	intsct;
	int		intsct_type;
}	t_cy;

union u_objects
{
	t_sp	sphere;
	t_pl	plane;
	t_cy	cylinder;
	t_co	cone;
};

typedef struct s_object
{
	char			e_idx;
	union u_objects	obj;
}	t_object;

typedef struct s_data
{
	int		num_sp;
	int		num_pl;
	int		num_cy;
	int		num_co;
	t_amb	ambience;
	t_cam	camera;
	t_light	light;
	t_list	*objects;
}	t_data;

typedef struct s_edit
{
	int			flag;
	t_object	*target;
}	t_edit;

typedef struct s_minirt
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	t_data	*file_data;
	t_edit	editor;
}	t_minirt;

typedef struct s_intrsct
{
	t_coord	r_vect;
	t_list	*obj_lst;
	t_coord	cam_pt;
}	t_intrsct;

#endif
