/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:09:58 by tvithara          #+#    #+#             */
/*   Updated: 2025/09/09 19:10:01 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

static void	try_move(t_game *game, int new_x, int new_y)
{
	char	tile;

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
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game, NULL);
	else if (keycode == 119 || keycode == 65362)
		try_move(game, game->player.x, game->player.y - 1);
	else if (keycode == 115 || keycode == 65364)
		try_move(game, game->player.x, game->player.y + 1);
	else if (keycode == 97 || keycode == 65361)
		try_move(game, game->player.x - 1, game->player.y);
	else if (keycode == 100 || keycode == 65363)
		try_move(game, game->player.x + 1, game->player.y);
	return (0);
}
