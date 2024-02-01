/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:46:23 by shechong          #+#    #+#             */
/*   Updated: 2024/01/25 14:34:50 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_display	display_init(int width, int height)
{
	t_camera	*camera;
	t_display	display;

	camera = malloc(sizeof(t_camera));
	*camera = (t_camera){(t_xy){1, 1}, (t_xy){1, 1}};
	display.camera = camera;
	display.dimensions = (t_xy){width, height};
	display.mlx = mlx_init();
	display.mlx_win = mlx_new_window
		(display.mlx, width, height, "Hello world!");
	display.grid_display = malloc(sizeof(t_grid_d));
	*(display.grid_display) = (t_grid_d){1, 1, 1, 1};
	display.mouse = (t_xy){0, 0};
	display.sprites = malloc(sizeof(t_img *) * 6);
	display.sprites[1] = img_from_path(WALL_SPRITE, display.mlx);
	display.sprites[2] = img_from_path(FLOOR_1_SPRITE, display.mlx);
	display.sprites[3] = img_from_path(FLOOR_2_SPRITE, display.mlx);
	display.sprites[4] = img_from_path(EXIT_SPRITE, display.mlx);
	display.sprites[5] = NULL;
	display.img = empty_img(display.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	return (display);
}

t_img	**frames(char *frames, char *directory, t_display *display)
{
	t_img	**array;
	char	**char_array;
	char	*path;
	int		i;

	char_array = ft_split(frames, ',');
	i = 0;
	while (char_array[i])
		i ++;
	array = malloc(sizeof(t_img *) * (i + 1));
	array[i - 1] = NULL;
	i = -1;
	while (char_array[++i])
	{
		path = ft_strjoin(directory, char_array[i]);
		array[i] = img_from_path(path, display->mlx);
		free(path);
	}
	ft_free_array((void *)(char_array), 0);
	array[i] = NULL;
	return (array);
}

t_world	*world_init(char *map, t_display *display)
{
	t_world		*world;
	t_player	*player;

	player = malloc(sizeof(t_player));
	world = malloc(sizeof(t_world));
	world->has_collected_all_collectibles = false;
	world->count = (t_counter){0, 0, 0, 0, 0};
	*world = ((t_world){player, NULL, NULL, scan_map(world, map),
			NULL, world->dimensions, (t_counter){0, 0, 0, 0, 0}, false, 0});
	*player = (t_player){(t_xy){1, 1}, (t_xy){1, 1}, (t_animator){0, 0, 30,
		frames(PLAYER_SPRITES, "assets/", display), 0}};
	player->animator.current_frame = world->player->animator.frames[0];
	world->collectibles = NULL;
	world->enemies = NULL;
	world->collectibles_collected = 0;
	world->tgrid = char2tile(world, count_newline(map, world), display);
	find_exit(world->grid, world);
	check(world->dimensions.x * world->dimensions.y > 700, "Map too big\n");
	return (world);
}
