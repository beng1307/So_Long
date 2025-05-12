/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:46:14 by bgretic           #+#    #+#             */
/*   Updated: 2025/05/12 11:14:42 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	remove_newline(char **map)
{
	int	line;
	int	column;

	line = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column] && map[line][column] != '\n')
			column++;
		if (map[line][column] == '\n')
			map[line][column] = '\0';
		line++;
	}
}

char	**parse_map(t_mlx **game, char *file_name, int *error)
{
	char	**map;
	char	*line;
	int		index;

	map = ft_calloc(32 * sizeof(char *), 1);
	if (!map)
		return (perror("malloc"), NULL);
	(*game)->file = open(file_name, O_RDONLY);
	if (!(*game)->file)
		return (free_str_arr(&map), perror("open"), NULL);
	index = 0;
	line = get_next_line((*game)->file, error);
	if (!line)
		return (free_str_arr(&map), NULL);
	while (line)
	{
		map[index++] = line;
		line = get_next_line((*game)->file, error);
		if (*error)
			return (free_str_arr(&map), NULL);
	}
	map[index] = NULL;
	remove_newline(map);
	return (map);
}
