#include "./../../includes/so_long.h"


static void flood_fill(t_map *map, int x, int y)
{
    if (x < 0 || y < 0 || y >= map->height || x >= map->width)
        return ;
    if (map->grid[y][x] == '1' || map->grid[y][x] == 'V')
        return ;
    map->grid[y][x] = 'V';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

static void	init_temp_game(t_game *temp_game, t_map *temp_map)
{
	temp_game->map = temp_map;
	temp_game->player.x = 0;
	temp_game->player.y = 0;
	temp_game->player.collected = 0;
}

static int dup_map(t_map *dst, t_map *src)
{
    int y;

    dst->width = src->width;
    dst->height = src->height;
    dst->collectibles = src->collectibles;
    dst->exits = src->exits;
    dst->players = src->players;
    dst->grid = malloc(sizeof(char *) * (src->height + 1));
    if (!dst->grid)
        return (0);
    y = 0;
    while (y < src->height)
    {
        dst->grid[y] = ft_strdup(src->grid[y]);
        if (!dst->grid[y])
            return (0);
        y++;
    }
    dst->grid[y] = NULL;
    return (1);
}

static void free_map_copy(t_map *map)
{
    int y;

    y = 0;
    while (y < map->height)
    {
        free(map->grid[y]);
        y++;
    }
    free(map->grid);
}

int check_path(t_map *map)
{
    t_map   temp_map;
    t_game  temp_game;
    int     y;
    int     x;

    if (!dup_map(&temp_map, map))
        return (0);
    init_temp_game(&temp_game,&temp_map);
    find_player(&temp_game);
    flood_fill(&temp_map, temp_game.player.x, temp_game.player.y);
    y = 0;
    while (y < temp_map.height)
    {
        x = 0;
        while (x < temp_map.width)
        {
            if (temp_map.grid[y][x] == 'C' || temp_map.grid[y][x] == 'E')
                return (free_map_copy(&temp_map), 0);
            x++;
        }
        y++;
    }
    free_map_copy(&temp_map);
    return (1);
}