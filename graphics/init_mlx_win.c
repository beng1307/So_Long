/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:45:58 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/11 17:20:57 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx(t_mlx **game)
{
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		exit_error(game, "Mlx initialisation failed!");
}

void	init_window(t_mlx **game)
{
	int	width;
	int	height;

	width = ft_strlen((*game)->map[0]) * 32;
	height = ft_linelen((*game)->map) * 32;
	(*game)->win = mlx_new_window((*game)->mlx, width, height, "So_Long");
	if (!(*game)->win)
		exit_error(game, "Window initalisation failed!");
}
