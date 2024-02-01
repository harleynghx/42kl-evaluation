/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:47:21 by shechong          #+#    #+#             */
/*   Updated: 2024/01/25 14:40:34 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_world *world, t_display *display, t_xy new_pos)
{
	t_tile	tile;

	tile = world->tgrid[new_pos.y][new_pos.x];
	if (tile.type == 'E')
	{
		if (!(world->count.collectible
				== world->collectibles_collected))
			return ;
		else
			exit_game(world, display);
	}
	ft_putstr_fd("steps moved: ", 1);
	ft_putnbr_fd(world->count.moves, 1);
	ft_putchar_fd('\n', 1);
	world->player->pos = new_pos;
	world->count.moves ++;
}

int	handle_keypress(int keycode, t_frame *frame)
{
	t_player	*player;
	t_xy		new_pos;
	t_tile		tile;

	player = frame->world->player;
	new_pos = player->pos;
	if (keycode == LINUX_W)
		new_pos.y --;
	else if (keycode == LINUX_A)
		new_pos.x --;
	else if (keycode == LINUX_S)
		new_pos.y ++;
	else if (keycode == LINUX_D)
		new_pos.x ++;
	tile = frame->world->tgrid[new_pos.y][new_pos.x];
	if (new_pos.x > 0 && new_pos.y > 0 && tile.type != '1' && tile.type != 'S')
		player_move(frame->world, frame->display, new_pos);
	if ((frame->world->tgrid[player->pos.y][player->pos.x].type) == 'C')
	{
		frame->world->collectibles_collected ++;
		frame->world->tgrid[player->pos.y][player->pos.x].type = '0';
	}
	return (0);
}

int	render_frame(void *param)
{
	t_frame			*data;
	t_world			*world;
	t_display		*display;

	data = (t_frame *)param;
	world = data->world;
	display = data->display;
	(*(data->frame_sec))++;
	if (*(data->frame_sec) < 100)
		return (1);
	clear_img(display->img);
	*(data->frame_sec) = 0;
	display->camera->pos = interpolate(display->camera->pos,
			(t_xy){world->player->mapped_pos.x + (display->mouse.x
				- (SCREEN_WIDTH / 2)) / 3, world->player->mapped_pos.y \
		+ (display->mouse.y - (SCREEN_HEIGHT / 2)) / 3}, 10);
	render_world(world, display);
	*(display->grid_display) = (t_grid_d){
		21, 21, ((display->dimensions.x) / 2) - display->camera->pos.x,
		((display->dimensions.y) / 2) - display->camera->pos.y};
	update_all_animators(display, world);
	mlx_put_image_to_window(display->mlx, display->mlx_win,
		display->img->img, 0, 0);
	render_ui(world, display);
	return (1);
}

int	mouse_hook(int x, int y, void *param)
{
	t_frame	*char_array;

	char_array = (t_frame *)param;
	char_array->display->mouse.x = x;
	char_array->display->mouse.y = y;
	return (1);
}
