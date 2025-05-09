/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_check_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:42:44 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/12 12:14:20 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_file_name(char *filename)
{
	if (!filename)
		return (false);
	if (!ft_strnstr(filename, ".ber", ft_strlen(filename)))
		return (false);
	if ((*filename == '.' && *(filename + 1) == 'b')
		|| (*filename == '.' && *(filename + 2) == '.'))
		return (false);
	return (true);
}

static void	is_the_map_rectangular(t_mlx **game)
{
	int	line_index;
	int	length_first_line;
	int	length_other_lines;

	line_index = 0;
	length_first_line = ft_strlen((*game)->map[line_index++]);
	while ((*game)->map[line_index])
	{
		length_other_lines = ft_strlen((*game)->map[line_index++]);
		if (length_first_line != length_other_lines)
			exit_error(game, "The map is not rectangular!");
	}
	if (length_first_line >= 40 || line_index >= 32)
		exit_error(game, "Map is too big!");
}

static void	is_the_map_content_correct(t_mlx **game)
{
	int	line_index;
	int	column_index;

	line_index = 0;
	column_index = 0;
	while ((*game)->map[line_index])
	{
		while ((*game)->map[line_index][column_index])
		{
			if (!ft_strchr("01CEP", (*game)->map[line_index][column_index++]))
				exit_error(game, "Map content is not correct!");
		}
		column_index = 0;
		line_index++;
	}
}

static char	**copy_map(char **map)
{
	int		line;
	char	**map_copy;

	line = 0;
	map_copy = (char **)malloc((ft_linelen(map) + 1) * sizeof(char *));
	if (!map_copy)
		return (perror("malloc"), NULL);
	while (map[line])
	{
		map_copy[line] = ft_strdup(map[line]);
		if (!map_copy[line])
			return (free_str_arr(&map_copy), NULL);
		line++;
	}
	map_copy[line] = NULL;
	return (map_copy);
}

void	parse_and_check_map(char *file_name, t_mlx **game)
{
	char	**map_copy;
	int		c_count;
	int		error;

	error = 0;
	(*game)->map = parse_map(game, file_name, &error);
	if (!(*game)->map)
		exit_error(game, "Map parsing failed!");
	is_the_map_rectangular(game);
	is_the_map_content_correct(game);
	is_the_map_complete(game);
	check_walls(game);
	get_player_pos(game);
	map_copy = copy_map((*game)->map);
	if (!map_copy)
		exit_error(game, "Map copy parsing failed!");
	c_count = count_collectibles(map_copy);
	if (!check_path(map_copy, (*game)->p_pos->y, (*game)->p_pos->x, &c_count))
	{
		free_str_arr(&map_copy);
		exit_error(game, "There is no possible exit!");
	}
	free_str_arr(&map_copy);
}
