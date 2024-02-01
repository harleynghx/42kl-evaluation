/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:53:58 by shechong          #+#    #+#             */
/*   Updated: 2024/01/25 14:07:06 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	recur(char **c, t_xy pos, t_world *world, bool *is_exit_found)
{
	int	collectible_count;

	collectible_count = 0;
	if (pos.x >= world->dimensions.x - 1 || pos.y >= world->dimensions.y -1
		|| pos.x < 0 || pos.y < 0 || c[pos.y][pos.x] == '1'
		|| c[pos.y][pos.x] == 'L')
		return (collectible_count);
	if (c[pos.y][pos.x] == 'E')
		*is_exit_found = true;
	if (c[pos.y][pos.x] == 'C')
		collectible_count ++;
	c[pos.y][pos.x] = 'L';
	collectible_count += recur(c, (t_xy){pos.x, pos.y + 1}, world,
			is_exit_found);
	collectible_count += recur(c, (t_xy){pos.x, pos.y - 1}, world,
			is_exit_found);
	collectible_count += recur(c, (t_xy){pos.x + 1, pos.y}, world,
			is_exit_found);
	collectible_count += recur(c, (t_xy){pos.x - 1, pos.y}, world,
			is_exit_found);
	return (collectible_count);
}

int	find_exit(char **c, t_world *world)
{
	bool	is_exit_reachable;
	char	**dup;
	int		collectible_count;

	is_exit_reachable = false;
	dup = dup_char_array(c);
	collectible_count = recur(dup, world->player->pos,
			world, &is_exit_reachable);
	if (collectible_count != world->count.collectible)
		exit(write(2, "Error: Not all collectibles are reachable\n", 43));
	if (!is_exit_reachable)
		exit(write(2, "Error: Player cannot reach exit\n", 32));
	ft_free_array((void **)dup, 0);
	return (is_exit_reachable);
}

char	**map2char_array(char *file, int rows)
{
	int		i;
	char	*buffer;
	char	**array;
	int		fd;

	fd = open(file, 0);
	i = 0;
	buffer = get_next_line(fd);
	array = malloc(sizeof(char *) * (rows + 1));
	while (buffer)
	{
		array[i++] = ft_substr(buffer, 0, ft_strrchr(buffer, '\n') - buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	array[i] = NULL;
	close(fd);
	return (array);
}

int	count_newline(char *filename, t_world *world)
{
	char	*buffer;
	int		fd;
	size_t	newline_count;
	size_t	prev_length;

	newline_count = 0;
	fd = open(filename, 0);
	buffer = get_next_line(fd);
	prev_length = ft_strlen(buffer);
	while (buffer)
	{
		newline_count++;
		count_items(buffer, world);
		check(ft_is_charset(buffer, VALID_CHAR) != 1,
			"Error: Invalid character found\n");
		check(prev_length != ft_strlen(buffer),
			"Error: Map is not rectangular\n");
		check(buffer[0] != '1' || buffer[ft_strlen(buffer) - 1] != '1',
			"Error: Not fully walled\n");
		prev_length = ft_strlen(buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (newline_count);
}
