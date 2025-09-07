#include "./../includes/so_long.h"

int main(int ac, char **av)
{
    t_map *map;
    t_game game;

    if(ac != 2)
        return (print_error("Error, usage: ./so_long map.ber"),1);
    
    // Add debug print to see what path is being used
    ft_printf("Trying to open: %s\n", av[1]); // Add this line

    //map = load_map(av[1]);
    map = load_map(av[1]);
    if(!map)
        return(print_error("Error: Map loading failed"),1);

    if(!validate_map(map))
    {
        free_map(map);
        return(print_error("Error: Invalid map"),1);
    }

    init_game(&game, map);
    render_map(&game);

    mlx_key_hook(game.win, handle_input, &game);
    mlx_hook(game.win, 17, 0, exit_game, &game); // evento "X" della finestra
    mlx_loop(game.mlx);
    
    return(0);

    
}