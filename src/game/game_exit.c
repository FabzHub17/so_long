/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:09:36 by tvithara          #+#    #+#             */
/*   Updated: 2025/09/09 19:09:41 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

static void	destroy_textures(t_game *game)
{
	int	i;

	if (!game || !game->mlx)
		return ;
	i = 0;
	while (i < 5)
	{
		if (game->textures[i])
			mlx_destroy_image(game->mlx, game->textures[i]);
		i++;
	}
}

int	window_close(t_game *game)
{
	exit_game(game, NULL);
	return (0);
}

int	exit_game(t_game *game, char *msg)
{
	if (!game)
	{
		if (msg)
			print_error(msg);
		exit(1);
	}
	destroy_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
	if (msg)
	{
		print_error(msg);
		exit(1);
	}
	exit(0);
	return (0);
}
