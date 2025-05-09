/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:39:56 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/11 17:21:02 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_sprites_out_of_assets(t_mlx **game, int *sprite_size)
{
	(*game)->sprites->player = mlx_xpm_file_to_image((*game)->mlx,
			"sprites/player.xpm", sprite_size, sprite_size);
	if (!(*game)->sprites->player)
		exit_error(game, "Sprite initialisation failed!");
	(*game)->sprites->exit_point = mlx_xpm_file_to_image((*game)->mlx,
			"sprites/door_closed.xpm", sprite_size, sprite_size);
	if (!(*game)->sprites->exit_point)
		exit_error(game, "Sprite initialisation failed!");
	(*game)->sprites->collectibles = mlx_xpm_file_to_image((*game)->mlx,
			"sprites/shroom.xpm", sprite_size, sprite_size);
	if (!(*game)->sprites->collectibles)
		exit_error(game, "Sprite initialisation failed!");
	(*game)->sprites->empty_spaces = mlx_xpm_file_to_image((*game)->mlx,
			"sprites/swamp.xpm", sprite_size, sprite_size);
	if (!(*game)->sprites->empty_spaces)
		exit_error(game, "Sprite initialisation failed!");
	(*game)->sprites->walls = mlx_xpm_file_to_image((*game)->mlx,
			"sprites/tree.xpm", sprite_size, sprite_size);
	if (!(*game)->sprites->walls)
		exit_error(game, "Sprite initialisation failed!");
}

void	init_sprites(t_mlx **game)
{
	int	sprite_size;

	sprite_size = 32;
	(*game)->sprites = ft_calloc(sizeof(t_assets), 1);
	if (!(*game)->sprites)
		exit_error(game, "Sprites couldn't get allocated!");
	get_sprites_out_of_assets(game, &sprite_size);
}
