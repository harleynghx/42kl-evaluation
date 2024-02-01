/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:54:06 by shechong          #+#    #+#             */
/*   Updated: 2024/01/30 11:52:19 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_obj(t_world *world, t_display *display, t_xy tile)
{
	t_tile		current_tile;
	t_img		**sprites;

	sprites = display->sprites;
	current_tile = world->tgrid[tile.y][tile.x];
	if (current_tile.type == '1')
		render_tile(display, sprites[1], (t_xy){tile.x, tile.y},
			(t_xy){0, (current_tile.type == '1') * -30});
	if (current_tile.type == 'E')
		render_tile(display, sprites[4],
			(t_xy){tile.x, tile.y}, (t_xy){0, -50});
	if (current_tile.type == 'S' && current_tile.data)
		render_sentry(display, (t_sentry *)((current_tile.data)));
	if (current_tile.type == 'C' && current_tile.data)
		render_tile(display,
			((t_collectible *)(current_tile.data))->animator.current_frame,
			tile, (t_xy){center(display->sprites[1],
				((t_collectible *)(current_tile.data))->animator.current_frame),
			-20});
	if (tile.x == world->player->pos.x && tile.y == world->player->pos.y)
		render_player(world, display);
}

int	draw_fov(t_sentry *enemy, t_display *display, t_img *char_array)
{
	t_xy		pos;
	t_grid_d	grid;

	grid = *(display->grid_display);
	draw_rect(char_array, (t_xy){100, 60}, (t_xy){0, 0}, 0xFFFF0000);
	pos = (t_xy){30, 0};
	draw_line(char_array, iso_map(pos),
		iso_map(move_in_dir(
				pos, enemy->current_angle + 20, 15)), SENTRY_FOV_COLOR);
	draw_line(char_array, iso_map(pos),
		iso_map(move_in_dir(
				pos, enemy->current_angle -20, 15)), SENTRY_FOV_COLOR);
	img_impose(display->img, char_array,
		(t_xy){iso_map((t_xy){
			enemy->pos.x * 21, enemy->pos.y * 21}).x + grid.offset_x - 14, \
			iso_map((t_xy){enemy->pos.x * 21, enemy->pos.y * 21}).y \
			+ grid.offset_y - 50}, (t_xy){1, 1});
	return (1);
}

int	render_sentry(t_display *display, t_sentry *enemy)
{
	t_grid_d	grid;

	grid = *(display->grid_display);
	enemy->current_pos = interpolate((t_xy){enemy->pos.x * grid.space_x,
			enemy->pos.y * grid.space_y}, enemy->current_pos, 2);
	img_impose(display->img,
		enemy->animator.frames[enemy->animator.frame_index],
		(t_xy){iso_map(enemy->current_pos).x + grid.offset_x
		+ center(display->sprites[1], enemy->animator.current_frame),
		iso_map(enemy->current_pos).y + grid.offset_y - 32}, (t_xy){1, 1});
	return (1);
}

int	render_player(t_world *world, t_display *display)
{
	t_player	*player;
	t_grid_d	grid;
	void		*img;

	grid = *(display->grid_display);
	player = world->player;
	world->player->mapped_pos = iso_map((t_xy){player->pos.x * grid.space_x,
			player->pos.y * grid.space_y});
	img = player->animator.frames[player->animator.frame_index];
	render_tile(display, img, player->pos, (t_xy){12, -44});
	return (1);
}
