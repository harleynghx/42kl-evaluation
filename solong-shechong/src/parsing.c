/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:47:29 by shechong          #+#    #+#             */
/*   Updated: 2024/01/30 10:45:22 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_holes(char **array, int rows)
{
	int	i;

	i = -1;
	if (!array || !array[0] || !array[0][0])
		return (0);
	while (array[0][++i])
		check(array[0][i] != '1' || array[rows - 1][i] != '1',
			"Error: Not fully walled\n");
	i = -1;
	while (array[++i])
		check(array[i][0] != '1' || array[i][ft_strlen(array[0]) - 1] != '1',
			"Error: Not fully walled\n");
	return (0);
}

void	count_items(char *array, t_world *world)
{
	int	i;

	i = -1;
	while (array[++i])
	{
		if (array[i] == 'P')
			world->count.player ++;
		if (array[i] == 'C')
			world->count.collectible ++;
		if (array[i] == 'E')
			world->count.exit ++;
	}
}

void	*create_obj(t_world *world, t_display *display, t_xy pos, char c)
{
	if (c == 'S')
		return (append(&world->enemies, new_obj(\
			"enemy", new_sentry(display, pos)))->data);
	if (c == 'C')
		return (append(&world->collectibles, \
	new_obj("c", new_collectible(display, pos)))->data);
	if (c == 'P')
		world->player->pos = pos;
	return (NULL);
}

t_tile	**char2tile(t_world *world, int row_count, t_display *display)
{
	t_xy	pos;
	t_tile	**map;

	map = malloc(sizeof(t_tile *) * (row_count + 1));
	pos.y = -1;
	while (++pos.y < row_count)
	{
		map[pos.y] = malloc(sizeof(t_tile) * ((ft_strlen(world->grid[0]) + 1)));
		pos.x = -1;
		while (++pos.x < (int)(ft_strlen(world->grid[pos.y])))
		{
			map[pos.y][pos.x] = (t_tile){world->grid[pos.y][pos.x], NULL};
			map[pos.y][pos.x].data = create_obj(world, display,
					pos, map[pos.y][pos.x].type);
		}
		map[pos.y][pos.x] = (t_tile){0, NULL};
	}
	map[pos.y] = NULL;
	return (map);
}

char	**scan_map(t_world *world, char *file)
{
	int		line_count;
	char	**char_array;
	int		fd;

	check(ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4),
		"Not a .ber file\n");
	fd = open(file, 0);
	check(fd == -1, "Error: Cannot read file\n");
	line_count = count_newline(file, world);
	check(world->count.player != 1, "Error: Incorrect number of players\n");
	check(world->count.exit < 1, "Error: No exit present\n");
	check(world->count.collectible < 1, "Error: No collectible present\n");
	check(line_count < 3, "Error: Incorrect length\n");
	char_array = map2char_array(file, line_count);
	find_holes(char_array, line_count);
	world->dimensions.y = line_count;
	world->dimensions.x = ft_strlen(char_array[0]);
	return (char_array);
}
