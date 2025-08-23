#include "./../../includes/so_long.h"

static int check_elemnts(t_map *map)
{
    if(map->players != 1)
        return(0);
    if(map->exits != 1)
        return(0);
    if(map->collectibles < 1)
        return(0);
    return(1);
}

static int check_walls(t_map *map)
{
    int x;
    int y;

    // prima e ultima riga
    x = 0;
    while(x < map->width)
    {
        if(map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
            return(0);
        x++;
    }
    // Bordi laterali
    y = 0;
    while(y < map->height)
    {
        if(map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
            return(0);
        y++;
    }
    return(1);
}

static int check_rectangle(t_map *map)
{
    int i;

    i = 0;
    while(i < map->height)
    {
        if(ft_strlen(map->grid[1]) != (size_t)map->width)
            return(0);
        i++;
    }
    return(1);
}

int validate_map(t_map *map)
{
    if(!check_rectangle(map))
        return (print_error("map not is rectangular"), 0);
    if(!check_walls(map))
        return (print_error("map not fully enclosed by walls"), 0);
    if(!check_elements(map))
        return (print_error("invalid number of P/E/C"), 0);

    // controllo del percorso valido: DA FARE

    return(1);
}