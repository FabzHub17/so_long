#include "./../includes/so_long.h"

int main(int ac, char **av)
{
    t_map *map;
    t_game game;

    if(ac != 2 || !check_ext(av[1]))
        return (print_error("Usage: ./so_long map.ber"),1);
    
    map = load_map(av[1]);
    if(!map)
        return(print_error("Map loading failed"),1);

    if(!validate_map(map))
    {
        free_map(map);
        return(print_error("Invalid map"),1);
    }

    init_game(&game, map);
    render_map(&game);

    mlx_key_hook(game.win, handle_input, &game);
    mlx_hook(game.win, 17, 0, window_close, &game); // evento "X" della finestra DA STUDIARE!!!
    mlx_loop(game.mlx);
    
    return(0);

    
}