#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

// MAP
#define WALL '1'
#define EMPTY '0'
#define PLAYER 'P'
#define EXIT 'E'
#define COLLECTIBLE 'C'

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

// ERRORS
int print_error(char *msg);

// MAP UTILS
void free_str_array(char **arr);
void free_map(t_map *map);


#endif