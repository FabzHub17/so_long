#include "./../../includes/so_long.h"

/*
Il ciclo con render_map(), è la funzione che disegna tutta la mappa nella finestra MLX.

funzione render_map(game):
    per ogni riga y della mappa:
        per ogni colonna x:
            disegna floor in (x, y)
            se cella è '1':
                disegna wall
            se cella è 'C':
                disegna collectible
            se cella è 'E':
                disegna exit
    disegna player nella sua posizione

*/

static void put_tile(t_game *game, void *img, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, img,
        x * TILE_SIZE, y * TILE_SIZE);
}

static void draw_cell(t_game *game, int x, int y)
{
    char c;

    c = game->map->grid[y][x];
    put_tile(game, game->textures[TX_FLOOR], x, y);
    if(c == WALL)
        put_tile(game, game->textures[TX_WALL], x, y);
    else if(c == COLLECTIBLE)
        put_tile(game, game->textures[TX_COLLECTIBLE], x, y);
    else if(c == EXIT)
        put_tile(game, game->textures[TX_EXIT], x, y);


}

void render_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while(y < game->map->height)
    {
        x = 0;
        while(x < game->map->width)
        {
            draw_cell(game,x,y);
            x++;
        }
        y++;
    }
    put_tile(game, game->textures[TX_PLAYER], game->player.x,game->player.y);
}

/*
🔍 Come funziona

(1) put_tile()

  Wrapper per mlx_put_image_to_window().

  Converte coordinate (x, y) in pixel → x * TILE_SIZE, y * TILE_SIZE.

(2) draw_cell()

  Per ogni cella:

    Disegna sempre il floor sotto.

    Se è muro ('1'), disegna il wall.

    Se è collectible ('C'), disegna collectible.

    Se è exit ('E'), disegna exit.

(3) render_map()

  Cicla tutta la mappa (height × width).

  Chiama draw_cell() su ogni cella.

  Alla fine disegna il player nella sua posizione aggiornata.

*/