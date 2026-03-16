/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:46:17 by tvithara          #+#    #+#             */
/*   Updated: 2025/09/09 18:46:21 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**append_line(char **tmp_array, char *line, int count)
{
	char	**new_tmp_array;
	int		i;

	i = 0;
	new_tmp_array = malloc(sizeof(char *) * (count + 2));
	if (!new_tmp_array)
		return (NULL);
	while (i < count)
	{
		new_tmp_array[i] = tmp_array[i];
		i++;
	}
	new_tmp_array[count] = line;
	new_tmp_array[count + 1] = NULL;
	free(tmp_array);
	return (new_tmp_array);
}

static char	**read_file(int fd)
{
	char	*line;
	char	**tmp_array;
	int		count;
	int		len;

	tmp_array = NULL;
	count = 0;
	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (print_error("File is empty"), NULL);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		tmp_array = append_line(tmp_array, line, count);
		if (!tmp_array)
			return (NULL);
		count++;
		line = get_next_line(fd);
	}
	return (tmp_array);
}

static void	count_elements(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == PLAYER)
				map->players++;
			else if (map->grid[y][x] == EXIT)
				map->exits++;
			else if (map->grid[y][x] == COLLECTIBLE)
				map->collectibles++;
			x++;
		}
		y++;
	}
}

static void	init_map(t_map *map, char **tmp_array)
{
	*map = (t_map){
		.grid = tmp_array,
		.height = 0,
		.width = 0,
		.players = 0,
		.exits = 0,
		.collectibles = 0};
	while (tmp_array[map->height])
		map->height++;
	map->width = ft_strlen(tmp_array[0]);
	count_elements(map);
}

t_map	*load_map(char *file)
{
	int		fd;
	char	**tmp_array;
	t_map	*map;

	tmp_array = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("Error in opening file"), NULL);
	tmp_array = read_file(fd);
	close(fd);
	if (!tmp_array)
		return (print_error("Failed to read file content"), NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (free_str_array(tmp_array), NULL);
	init_map(map, tmp_array);
	return (map);
}
