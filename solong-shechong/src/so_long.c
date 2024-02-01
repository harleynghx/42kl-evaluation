/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:47:09 by shechong          #+#    #+#             */
/*   Updated: 2024/01/31 10:52:35 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keys(int keycode, t_frame *frame)
{
	if (keycode == ON_ESCAPE)
		exit_hook(frame);
	return (0);
}

int	main(int ac, char **av)
{
	t_display	display;
	t_world		*world;
	t_frame		frame;
	int			frame_sec;

	check(ac != 2, "Incorrect argument count\n");
	display = display_init(SCREEN_WIDTH, SCREEN_HEIGHT);
	world = world_init(av[1], &display);
	frame_sec = 0;
	frame = (t_frame){&frame_sec, world, &display};
	mlx_hook(display.mlx_win, ON_KEY_PRESS, 1L << 0, handle_keypress, &frame);
	mlx_loop_hook(display.mlx, render_frame, &frame);
	mlx_hook(display.mlx_win, ON_MOUSE_MOTION, 1L << 6, mouse_hook, &frame);
	mlx_hook(display.mlx_win, ON_DESTROY, 0, exit_hook, &frame);
	mlx_key_hook(display.mlx_win, handle_keys, &frame);
	mlx_loop(display.mlx);
}
