# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 12:32:52 by bgretic           #+#    #+#              #
#    Updated: 2024/09/12 15:45:29 by bgretic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#for compiling
COMPILE = cc -g -Wall -Werror -Wextra


#including mlx
MLX = -lmlx -lXext -lX11


#make libft.a
LIBFT = libft/libft.a

LIBFT_H = -I libft


#So_Long
SO_LONG = so_long

SO_LONG_SRCS = main.c \
map/check_path.c map/check_walls.c map/is_the_map_complete.c \
map/parse_map.c map/parse_and_check_map.c \
graphics/init_mlx_win.c graphics/init_sprites.c \
graphics/put_background.c graphics/put_map_content.c \
events/all_collectibles_collected.c events/open_door.c \
events/handle_keys.c events/handle_events.c \
events/exit_game.c map/get_player_pos.c  

SO_LONG_OBJS = $(SO_LONG_SRCS:.c=.o)


$(SO_LONG): $(SO_LONG_OBJS) $(LIBFT)
	$(COMPILE) $(SO_LONG_OBJS) $(LIBFT) $(MLX) -o $(SO_LONG)

$(LIBFT):
	cd libft && make all

#anti-relink
%.o: %.c
	$(COMPILE) $(LIBFT_H) -c $< -o $@


#commands
all: $(SO_LONG)

clean:
	@rm -f $(SO_LONG_OBJS)
	@cd libft && make clean

fclean:	clean
	@rm -f $(SO_LONG)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
