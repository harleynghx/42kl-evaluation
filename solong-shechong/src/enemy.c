/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:47:16 by shechong          #+#    #+#             */
/*   Updated: 2024/01/25 14:44:45 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sentry_move(t_sentry *enemy, t_xy pos, t_world *world)
{
	if (pos.x < world->dimensions.x
		&& pos.y < world->dimensions.y
		&& world->tgrid[pos.y][pos.x].type != 'S'
		&& world->tgrid[pos.y][pos.x].type != '1'
		&& world->tgrid[pos.y][pos.x].type != 'E')
	{
		world->tgrid[enemy->pos.y][enemy->pos.x].type = '0';
		world->tgrid[enemy->pos.y][enemy->pos.x].data = NULL;
		enemy->pos = pos;
		world->tgrid[pos.y][pos.x].type = 'S';
		world->tgrid[pos.y][pos.x].data = enemy;
	}
}

int	sentry_decide_move_vect(t_world *world, t_sentry *enemy)
{
	if (world->player->pos.x - enemy->pos.x > 0)
		sentry_move(enemy, (t_xy){enemy->pos.x + 1, enemy->pos.y}, world);
	if (world->player->pos.x - enemy->pos.x < 0)
		sentry_move(enemy, (t_xy){enemy->pos.x - 1, enemy->pos.y}, world);
	if (world->player->pos.y - enemy->pos.y > 0)
		sentry_move(enemy, (t_xy){enemy->pos.x, enemy->pos.y + 1}, world);
	if (world->player->pos.y - enemy->pos.y < 0)
		sentry_move(enemy, (t_xy){enemy->pos.x, enemy->pos.y - 1}, world);
	return (1);
}

int	sentry_fov_raycast(t_world *world, t_sentry *enemy)
{
	if (enemy->alert)
	{
		enemy->final_angle = vec2_to_angle(enemy->pos, world->player->pos);
		enemy->current_angle = vec2_to_angle(enemy->pos, world->player->pos);
	}
	if (ray_cast(world, enemy->pos, enemy->current_angle, 10) == 1
		|| ray_cast(world, enemy->pos, enemy->current_angle + 20, 10) == 1
		|| ray_cast(world, enemy->pos, enemy->current_angle - 20, 10) == 1)
	{
		enemy->player_found = true;
		enemy->final_angle = enemy->current_angle;
		enemy->alert = SENTRY_MAX_ALERT;
	}
	else
		enemy->alert = 0;
	return (1);
}

void	update_sentry(t_world *world, t_display *display, t_sentry *enemy)
{
	if (enemy->pos.x == world->player->pos.x
		&& enemy->pos.y == world->player->pos.y)
		exit_game(world, display);
	enemy->current_angle = enemy->current_angle
		+ (enemy->final_angle - enemy->current_angle) / 10;
	enemy->player_found = 0;
	sentry_fov_raycast(world, enemy);
	if (ran_int(1, SENTRY_TURN_RATE) == 1 && enemy->player_found == 0)
		enemy->final_angle += ran_int(-180, 180);
	if (enemy->player_found == 1
		&& (enemy->time.elapsed == 0))
		sentry_decide_move_vect(world, enemy);
	enemy->alert -= (enemy->alert > 0);
}

void	update_sentries(t_world *world, t_display *display)
{
	t_sentry	*enemy;
	t_object	*head;
	t_img		*char_array;

	char_array = empty_img(display->mlx, 100, 60);
	head = world->enemies;
	while (head)
	{
		enemy = (t_sentry *)(head->data);
		update_sentry(world, display, enemy);
		draw_fov(enemy, display, char_array);
		enemy->time.elapsed = (enemy->time.elapsed + 1) % SENTRY_MOVEMENT_DAY;
		head = head->next;
	}
	free(char_array);
}
