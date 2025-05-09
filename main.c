/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:42:51 by bgretic           #+#    #+#             */
/*   Updated: 2024/09/12 10:52:58 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx	*game;

	if (ac != 2)
		return (ft_printf("Error\nWrite the right amount of arguments!\n"), 1);
	if (!check_file_name(av[1]))
		return (ft_printf("Error\nThe filename is not correct!\n"), 1);
	game = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	if (!game)
		return (perror("malloc"), 1);
	parse_and_check_map(av[1], &game);
	init_mlx(&game);
	init_window(&game);
	init_sprites(&game);
	put_background(&game, ft_strlen(game->map[0]), ft_linelen(game->map));
	put_map_content(game);
	handle_events(&game);
	mlx_loop(game->mlx);
}
