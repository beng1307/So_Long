/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:39:52 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/12 12:55:23 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_top_and_bottom_wall(t_mlx **game)
{
	int	column;
	int	lst_line;

	column = 0;
	lst_line = ft_linelen((*game)->map) - 1;
	while ((*game)->map[0][column] && (*game)->map[lst_line][column])
	{
		if (!ft_strchr("1", (*game)->map[0][column]) || !ft_strchr("1",
				(*game)->map[lst_line][column++]))
			exit_error(game, "Walls are not ok!");
	}
}

static void	check_walls_in_between(t_mlx **game)
{
	int	line;
	int	lst_col;

	line = 1;
	lst_col = ft_strlen((*game)->map[0]) - 1;
	while ((*game)->map[line + 1])
	{
		if ((*game)->map[line][0] != '1' || (*game)->map[line][lst_col] != '1')
			exit_error(game, "Walls are not ok!");
		line++;
	}
}

void	check_walls(t_mlx **game)
{
	check_top_and_bottom_wall(game);
	check_walls_in_between(game);
}
