/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_collectibles_collected.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:45:07 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/11 17:20:27 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	all_collectibles_collected(t_mlx **game)
{
	int	line;
	int	column;

	if ((*game)->collected)
		return ;
	line = 0;
	column = 0;
	while ((*game)->map[line])
	{
		while ((*game)->map[line][column])
		{
			if ((*game)->map[line][column] == 'C')
				return ;
			column++;
		}
		column = 0;
		line++;
	}
	(*game)->collected = true;
}
