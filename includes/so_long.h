#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>
#include "./get_next_line.h"
#include "./ft_printf.h"
#include "../minilibx/mlx.h"

// MAP
#define WALL '1'
#define EMPTY '0'
#define PLAYER 'P'
#define EXIT 'E'
#define COLLECTIBLE 'C'

// Indici per l’array di textures
# define TX_FLOOR 0
# define TX_WALL 1
# define TX_PLAYER 2
# define TX_EXIT 3
# define TX_COLLECTIBLE 4

# define TILE_SIZE 32


// t_map (serve per gestire la mappa, verificarla, validarla e usarla nel rendering)
typedef struct s_map
{
    char        **grid;
    int         width;
    int         height;
    int         collectibles;
    int         exits;
    int         players;
}               t_map;

// t_player (tiene traccia della posizione del player e degli oggetti raccolti)
typedef struct s_player
{
    int     x;
    int     y;
    int     collected;
}           t_player;

// t_game (struttura principale che contiene lo stato globale del gioco)
typedef struct s_game
{
    void        *mlx;
    void        *win;
    t_map       *map;
    t_player    player;
    int         moves;
    void        *textures[5]; // floor, wall, collectibles, player, exit
}               t_game;



// UTILS
void free_str_array(char **arr);
void free_map(t_map *map);
int print_error(char *msg);



// MAP
t_map *load_map(char *file);
int validate_map(t_map *map);


// RENDER
void render_map(t_game *game);

// GAME
void init_game(t_game *game, t_map *map);
int handle_input(int keycode, t_game *game);
int exit_game(t_game *game, char *msg);

#endif