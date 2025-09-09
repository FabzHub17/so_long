#include "./../../includes/so_long.h"
/*
funzione init_game(game, map):
    1. inizializza il contesto grafico:
        game->mlx = mlx_init()
        se NULL → errore e uscita
    
    2. crea la finestra:
        game->win = mlx_new_window(mlx, map->width * TILE_SIZE,
                                   map->height * TILE_SIZE, "so_long")
        se NULL → errore e uscita
    
    3. salva la mappa dentro game:
        game->map = map
    
    4. inizializza player:
        cerca 'P' nella griglia della mappa
        salva le coordinate in game->player.x / y
        setta game->player.collected = 0
    
    5. inizializza il contatore mosse:
        game->moves = 0
    
    6. carica tutte le texture (.xpm) in game->textures[]
        se manca una texture → errore e uscita

*/


static void load_textures(t_game *game)
{
    int w;
    int h;

    game->textures[TX_WALL] = mlx_xpm_file_to_image(game->mlx,
            "textures/wall.xpm", &w, &h);
    game->textures[TX_FLOOR] = mlx_xpm_file_to_image(game->mlx,
            "textures/floor.xpm", &w, &h);
    game->textures[TX_PLAYER] = mlx_xpm_file_to_image(game->mlx,
            "textures/player.xpm", &w, &h);
    game->textures[TX_EXIT] = mlx_xpm_file_to_image(game->mlx,
            "textures/exit.xpm", &w, &h);
    game->textures[TX_COLLECTIBLE] = mlx_xpm_file_to_image(game->mlx,
            "textures/collectible.xpm", &w, &h);
    if (!game->textures[TX_WALL] || !game->textures[TX_FLOOR]
        || !game->textures[TX_PLAYER] || !game->textures[TX_EXIT]
        || !game->textures[TX_COLLECTIBLE])
    {
        exit_game(game, "Error: failed to load textures");
    }

}

void find_player(t_game *game)
{
    int x;
    int y;

    y = 0;
    while(y < game->map->height)
    {
        x = 0;
        while(x < game->map->width)
        {
            if(game->map->grid[y][x] == PLAYER)
            {
                game->player.x = x;
                game->player.y = y;
                return;
            }
            x++;
        }
        y++;
    }
}
void init_game(t_game *game, t_map *map)
{
    game->mlx = mlx_init();
    if(!game->mlx)
        exit_game(game,"Error: mlx_init failed");
    game->win = mlx_new_window(game->mlx, map->width * TILE_SIZE,
         map->height * TILE_SIZE,"so_long");  // What is TILE_SIZE???
    if(!game->win)
        exit_game(game, "Error: window creation failed");
    game->map  = map;
    game->moves = 0;
    game->player.collected = 0; // should this be here???
    find_player(game);
    load_textures(game);
}