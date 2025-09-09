#include "./../../includes/so_long.h"

/*
funzione exit_game(game, msg):
    1. se game->textures[] non è vuoto:
        distruggi ogni immagine con mlx_destroy_image()
    
    2. se game->win non è NULL:
        chiudi la finestra con mlx_destroy_window()
    
    3. se game->mlx non è NULL:
        libera display con mlx_destroy_display() (solo Linux)
        free(game->mlx)
    
    4. libera la mappa con free_map()
    
    5. se msg != NULL:
        stampa "Error\n" + msg su stderr
    
    6. esci dal programma con exit(1 se errore, 0 se normale)
*/

static void destroy_textures(t_game *game)
{
    int i;

    if (!game || !game->mlx)
        return;  // ADDED LATER NEEDED??

    i = 0;
    while (i < 5)
    {
        if (game->textures[i])
            mlx_destroy_image(game->mlx, game->textures[i]);
        i++;
    }
}

// New function to handle the window close event (with correct signature)
int window_close(t_game *game)
{
    exit_game(game, NULL);
    return (0);
}

int exit_game(t_game *game, char *msg)
{

    if (!game)  // ADDED LATER NEEDED???
    {
        if (msg)
            print_error(msg);
        exit(1);
    }

    destroy_textures(game);
    if(game->win)
        mlx_destroy_window(game->mlx, game->win);
    if(game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    if(game->map)
        free_map(game->map);
    if(msg)
    {
        print_error(msg);
        exit(1);
    }
    exit(0);
    return(0);
}

/* int exit_game(void *param)
{
    t_game *game = (t_game *)param;
    
    if (!game)
        exit(0);
    
    destroy_textures(game);
    
    if (game->win && game->mlx)
        mlx_destroy_window(game->mlx, game->win);
        
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    
    if (game->map)
        free_map(game->map);
        
    exit(0);
    return (0);
} */