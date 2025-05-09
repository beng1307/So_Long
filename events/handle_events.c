/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:45:50 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/11 17:20:37 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	handle_keys(int key, t_mlx **game)
{
	if (key == UP)
		move_up(game);
	else if (key == DOWN)
		move_down(game);
	else if (key == LEFT)
		move_left(game);
	else if (key == RIGHT)
		move_right(game);
	else if (key == ESCAPE)
		exit_game(game);
	all_collectibles_collected(game);
	open_door(game);
	return (0);
}

void	handle_events(t_mlx **game)
{
	mlx_key_hook((*game)->win, handle_keys, game);
	mlx_hook((*game)->win, 17, 0, exit_game, game);
}
