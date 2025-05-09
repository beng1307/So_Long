/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:43:01 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/12 12:13:45 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESCAPE 65307

typedef struct s_player_pos
{
	int				x;
	int				y;
}					t_player_pos;

typedef struct s_assets
{
	void			*player;
	void			*exit_point;
	void			*collectibles;
	void			*empty_spaces;
	void			*walls;
}					t_assets;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	char			**map;
	t_assets		*sprites;
	t_player_pos	*p_pos;
	int				moves;
	int				file;
	bool			collected;
}					t_mlx;

bool				check_file_name(char *filename);

int					count_collectibles(char **map);

char				**parse_map(t_mlx **game, char *file_name, int *error);

void				move_up(t_mlx **game);

void				move_down(t_mlx **game);

void				move_left(t_mlx **game);

void				move_right(t_mlx **game);

void				open_door(t_mlx **game);

bool				check_path(char **map, int y, int x, int *c_count);

void				all_collectibles_collected(t_mlx **game);

void				get_player_pos(t_mlx **game);

void				parse_and_check_map(char *file_name, t_mlx **game);

void				is_the_map_complete(t_mlx **game);

void				check_walls(t_mlx **game);

int					exit_error(t_mlx **game, char *message);

int					exit_game(t_mlx **game);

void				init_mlx(t_mlx **game);

void				init_window(t_mlx **game);

void				init_sprites(t_mlx **game);

void				put_background(t_mlx **game, int win_width, int win_height);

void				put_map_content(t_mlx *game);

void				handle_events(t_mlx **game);

#endif