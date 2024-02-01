/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:46:43 by shechong          #+#    #+#             */
/*   Updated: 2024/01/25 13:57:22 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*empty_img(void *mlx, int x, int y)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(mlx, x, y);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	img->width = x;
	img->height = y;
	return (img);
}

t_img	*img_from_path(char *image, void *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(mlx, image, &img->width, &img->height);
	if (img->img == NULL)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	return (img);
}

int	img_impose(t_img *canvas, t_img *img, t_xy start, t_xy scaling)
{
	t_xy	pix;
	int		color;

	pix = (t_xy){-1, -1};
	scaling = (t_xy){img->width * scaling.x, img->height * scaling.y};
	while (++pix.y < scaling.y)
	{
		pix.x = -1;
		while (++pix.x < scaling.x && pix.x + start.x < SCREEN_WIDTH
			&& pix.y + start.y < SCREEN_HEIGHT)
		{
			if (!(start.x + pix.x > 0 && start.y + pix.y > 0))
				continue ;
			if (scaling.x == img->width && scaling.y == img->height)
				color = get_color(img, pix.x, pix.y);
			else
				color = get_color(img, (int)(((double)pix.x
								/ (double)scaling.x) * img->width), \
				(int)(((double)pix.y / (double)scaling.y) * img->height));
			if (color != C_MLX_TRANSPARENT && (unsigned int)color
				!= C_TRANSPARENT)
				put_pixel(canvas, pix.x + start.x, pix.y + start.y, color);
		}
	}
	return (1);
}

int	clear_img(t_img *img)
{
	t_xy	pix;

	pix = (t_xy){-1, -1};
	while (++pix.y < img->height)
	{
		pix.x = -1;
		while (++pix.x < img->width)
			put_pixel(img, pix.x, pix.y, COLOR_BLACK);
	}
	return (1);
}
