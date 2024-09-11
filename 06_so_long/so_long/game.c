/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:27 by hepereir          #+#    #+#             */
/*   Updated: 2024/09/11 22:50:37 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_pressed_x(t_game *game)
{
	mlx_loop_end(game->mlx.mlx_ptr);
	return (1);
}

static int	ft_move(t_game *game, int x, int y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = x;
	game->player_y = y;
	game->map[y][x] = 'P';
	ft_map_visualizer(game);
	return (1);
}

static int	ft_check_movement(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'C')
	{
		game->collectible_count--;
		game->map[y][x] = '0';
	}
	if (game->map[y][x] == 'E')
	{
		if (game->collectible_count == 0)
			ft_pressed_x(game);
		else
			return (1);
	}
	ft_move(game, x, y);
	game->steps++;
	ft_printf("Steps:\t%d\n", game->steps);
	return (1);
}

static int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Up || keysym == XK_w)
		ft_check_movement(game, game->player_x, game->player_y - 1);
	else if (keysym == XK_Down || keysym == XK_s)
		ft_check_movement(game, game->player_x, game->player_y + 1);
	else if (keysym == XK_Right || keysym == XK_d)
		ft_check_movement(game, game->player_x + 1, game->player_y);
	else if (keysym == XK_Left || keysym == XK_a)
		ft_check_movement(game, game->player_x - 1, game->player_y);
	else if (keysym == XK_Escape)
	{
		ft_pressed_x(game);
		return (1);
	}
	return (0);
}

void	ft_game_start(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
		return ;
	if (ft_screen_size(game))
	{
		ft_game_cleanup(game);
		return ;
	}	
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, game->map_width * 32,
			game->map_heigth * 32, "So Long!");
	if (game->mlx.win_ptr == NULL)
	{
		ft_game_cleanup(game);
		return ;
	}
	ft_init_images(game);
	ft_map_visualizer(game);
	mlx_hook(game->mlx.win_ptr, DestroyNotify, NoEventMask, ft_pressed_x, game);
	mlx_hook(game->mlx.win_ptr, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_loop(game->mlx.mlx_ptr);
	ft_game_cleanup(game);
}
