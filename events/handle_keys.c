/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:45:55 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/11 17:20:45 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_mlx **game)
{
	if ((*game)->map[(*game)->p_pos->y - 1][(*game)->p_pos->x] != '1'
		&& (*game)->map[(*game)->p_pos->y - 1][(*game)->p_pos->x] != 'E')
	{
		(*game)->map[(*game)->p_pos->y - 1][(*game)->p_pos->x] = 'P';
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x] = '0';
		(*game)->p_pos->y--;
		mlx_put_image_to_window(
			(*game)->mlx, (*game)->win, (*game)->sprites->player,
			(*game)->p_pos->x * 32, (*game)->p_pos->y * 32);
		mlx_put_image_to_window(
			(*game)->mlx, (*game)->win, (*game)->sprites->empty_spaces,
			(*game)->p_pos->x * 32, ((*game)->p_pos->y + 1) * 32);
		(*game)->moves++;
		ft_printf("Move: %d\n", (*game)->moves);
	}
	else if ((*game)->map[(*game)->p_pos->y - 1][(*game)->p_pos->x] == 'E'
		&& (*game)->collected == true)
	{
		ft_putendl_fd("You won, thank you for playing!", 1);
		exit_game(game);
	}
}

void	move_down(t_mlx **game)
{
	if ((*game)->map[(*game)->p_pos->y + 1][(*game)->p_pos->x] != '1'
		&& (*game)->map[(*game)->p_pos->y + 1][(*game)->p_pos->x] != 'E')
	{
		(*game)->map[(*game)->p_pos->y + 1][(*game)->p_pos->x] = 'P';
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x] = '0';
		(*game)->p_pos->y++;
		mlx_put_image_to_window(
			(*game)->mlx, (*game)->win, (*game)->sprites->player,
			(*game)->p_pos->x * 32, (*game)->p_pos->y * 32);
		mlx_put_image_to_window(
			(*game)->mlx, (*game)->win, (*game)->sprites->empty_spaces,
			(*game)->p_pos->x * 32, ((*game)->p_pos->y - 1) * 32);
		(*game)->moves++;
		ft_printf("Move: %d\n", (*game)->moves);
	}
	else if ((*game)->map[(*game)->p_pos->y + 1][(*game)->p_pos->x] == 'E'
		&& (*game)->collected == true)
	{
		ft_putendl_fd("You won, thank you for playing!", 1);
		exit_game(game);
	}
}

void	move_left(t_mlx **game)
{
	if ((*game)->map[(*game)->p_pos->y][(*game)->p_pos->x - 1] != '1'
		&& (*game)->map[(*game)->p_pos->y][(*game)->p_pos->x - 1] != 'E')
	{
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x - 1] = 'P';
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x] = '0';
		(*game)->p_pos->x--;
		mlx_put_image_to_window(
			(*game)->mlx, (*game)->win, (*game)->sprites->player,
			(*game)->p_pos->x * 32, (*game)->p_pos->y * 32);
		mlx_put_image_to_window(
			(*game)->mlx, (*game)->win, (*game)->sprites->empty_spaces,
			((*game)->p_pos->x + 1) * 32, (*game)->p_pos->y * 32);
		(*game)->moves++;
		ft_printf("Move: %d\n", (*game)->moves);
	}
	else if ((*game)->map[(*game)->p_pos->y][(*game)->p_pos->x - 1] == 'E'
		&& (*game)->collected == true)
	{
		ft_putendl_fd("You won, thank you for playing!", 1);
		exit_game(game);
	}
}

void	move_right(t_mlx **game)
{
	if ((*game)->map[(*game)->p_pos->y][(*game)->p_pos->x + 1] != '1'
		&& (*game)->map[(*game)->p_pos->y][(*game)->p_pos->x + 1] != 'E')
	{
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x + 1] = 'P';
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x] = '0';
		(*game)->p_pos->x++;
		mlx_put_image_to_window(
			(*game)->mlx, (*game)->win, (*game)->sprites->player,
			(*game)->p_pos->x * 32, (*game)->p_pos->y * 32);
		mlx_put_image_to_window(
			(*game)->mlx, (*game)->win, (*game)->sprites->empty_spaces,
			((*game)->p_pos->x - 1) * 32, (*game)->p_pos->y * 32);
		(*game)->moves++;
		ft_printf("Move: %d\n", (*game)->moves);
	}
	else if ((*game)->map[(*game)->p_pos->y][(*game)->p_pos->x + 1] == 'E'
		&& (*game)->collected == true)
	{
		ft_putendl_fd("You won, thank you for playing!", 1);
		exit_game(game);
	}
}
