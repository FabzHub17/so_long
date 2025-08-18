#include "./../includes/so_long.h"

int main(int ac, char **av)
{
    t_map *map;
    t_game game;

    if(ac != 2)
        return (ft_printf("Error, usage: ./so_long map.ber"),1);

    map = load_map(av[1]);
    if(!map)
        return(ft_printf("Error: Map loading failed"),1);

    if(!validate_map(map))
    {
        free_map(map);
        return(ft_print("Error: Invalid map",1));
    }

    init_game(&game, map);
    render_map(&game);
    
    return(0);

    
}