#include "./../../includes/so_long.h"

/*
funzione handle_input(keycode, game):
    se keycode == ESC:
        chiama exit_game(game, NULL)  // uscita pulita senza errore

    se keycode == W:
        prova a muovere player in alto
    se keycode == S:
        prova a muovere player in basso
    se keycode == A:
        prova a muovere player a sinistra
    se keycode == D:
        prova a muovere player a destra

    se il movimento è valido (non muro):
        aggiorna posizione player
        se casella è 'C':
            incrementa collected e rimuovi collectible
        se casella è 'E' e tutti i collectibles presi:
            chiama exit_game(game, NULL)
        incrementa moves
        stampa moves su stdout
        render_map(game)  // ridisegna mappa aggiornata 
*/

static void try_move(t_game *game, int new_x, int new_y)
{
    char tile;

    tile = game->map->grid[new_y][new_x];
    if (tile == WALL)
        return ;
    if (tile == 'C')
    {
        game->player.collected++;
        game->map->grid[new_y][new_x] = '0';
    }
    if (tile == 'E' && game->player.collected == game->map->collectibles)
        exit_game(game, NULL);
    game->player.x = new_x;
    game->player.y = new_y;
    game->moves++;
    ft_printf("Moves: %d\n", game->moves);
    render_map(game);


    /*
    try_move()

        Legge la tile della mappa (map->grid[new_y][new_x]).

        Se è WALL → ignora movimento.

        Se è C → aumenta collected e rimuove il collectible ('0').

        Se è E ed hai preso tutti i collectibles → vinci e chiudi gioco.

        Aggiorna posizione player.

        Incrementa moves e stampa in shell.

        Richiama render_map() per aggiornare la finestra. 
    */
}

int handle_input(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC su Linux
        exit_game(game, NULL);
    else if (keycode == 119 || keycode == 65362) // W
        try_move(game, game->player.x, game->player.y - 1);
    else if (keycode == 115 || keycode == 65364) // S
        try_move(game, game->player.x, game->player.y + 1);
    else if (keycode == 97 || keycode == 65361) // A
        try_move(game, game->player.x - 1, game->player.y);
    else if (keycode == 100 || keycode == 65363) // D
        try_move(game, game->player.x + 1, game->player.y);
    return (0);
}