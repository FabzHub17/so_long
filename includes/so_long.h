/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:58:27 by tvithara          #+#    #+#             */
/*   Updated: 2025/09/09 19:58:30 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "./ft_printf.h"
# include "./get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// MAP
# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

// Inexes for textures array
# define TX_FLOOR 0
# define TX_WALL 1
# define TX_PLAYER 2
# define TX_EXIT 3
# define TX_COLLECTIBLE 4

# define TILE_SIZE 32

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			collectibles;
	int			exits;
	int			players;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			collected;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	player;
	int			moves;
	void		*textures[5];
}				t_game;

// UTILS
void			free_str_array(char **arr);
void			free_map(t_map *map);
int				print_error(char *msg);
void			*ft_memset(void *ptr, int c, size_t n);
char			*ft_strdup(const char *s);
int				check_ext(char *filename);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

// MAP
t_map			*load_map(char *file);
int				validate_map(t_map *map);
int				check_path(t_map *map);

// RENDER
void			render_map(t_game *game);

// GAME
void			init_game(t_game *game, t_map *map);
int				handle_input(int keycode, t_game *game);
int				exit_game(t_game *game, char *msg);
int				window_close(t_game *game);
void			find_player(t_game *game);

#endif
