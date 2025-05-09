/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:45:34 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/12 15:47:41 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_collectibles(char **map)
{
	int	line;
	int	column;
	int	count;

	line = 0;
	count = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column])
		{
			if (map[line][column] == 'C')
				count++;
			column++;
		}
		line++;
	}
	return (count);
}

static bool	exit_found(char map_coord)
{
	static bool	exit_possible = false;

	if (map_coord == 'E')
		exit_possible = true;
	return (exit_possible);
}

bool	check_path(char **map, int y, int x, int *c_count)
{
	if (exit_found(map[y][x]) && !*c_count)
		return (true);
	else if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'E')
		return (false);
	else if (map[y][x] == 'C')
		(*c_count)--;
	map[y][x] = 'X';
	if (check_path(map, y - 1, x, c_count))
		return (true);
	if (check_path(map, y + 1, x, c_count))
		return (true);
	if (check_path(map, y, x - 1, c_count))
		return (true);
	if (check_path(map, y, x + 1, c_count))
		return (true);
	return (false);
}
