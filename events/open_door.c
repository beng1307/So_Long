/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:45:18 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/11 17:20:49 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_door(t_mlx **game)
{
	static bool	already_done = false;
	int			sprite_size;

	if (already_done)
		return ;
	sprite_size = 32;
	if ((*game)->collected)
	{
		mlx_destroy_image((*game)->mlx, (*game)->sprites->exit_point);
		(*game)->sprites->exit_point = mlx_xpm_file_to_image((*game)->mlx,
				"sprites/door_open.xpm", &sprite_size, &sprite_size);
		if (!(*game)->sprites->exit_point)
			exit_error(game, "Door didn't open!");
		put_map_content(*game);
		already_done = true;
	}
}
