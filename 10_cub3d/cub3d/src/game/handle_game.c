/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:40:00 by jalves-v          #+#    #+#             */
/*   Updated: 2025/05/07 13:00:45 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Init the game by setting up the mlx graphics system,
// window, and image buffer
int	init_game(t_data *data)
{
	data->graphics.mlx = mlx_init();
	if (!data->graphics.mlx)
		return (-1);
	data->graphics.win = mlx_new_window(data->graphics.mlx,
			WIDTH, HEIGHT, "cub3D");
	if (!data->graphics.win)
	{
		mlx_destroy_display(data->graphics.mlx);
		free(data->graphics.mlx);
		return (-1);
	}
	data->img.img = mlx_new_image(data->graphics.mlx, WIDTH,
			HEIGHT);
	if (!data->img.img)
		return (free_mlx_ptr(data, false));
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!data->img.addr)
		return (free_mlx_ptr(data, true));
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->img.img, 0, 0);
	return (0);
}

static void	move_player_aux(int key, t_data *data)
{
	if (key == 0x73)
		data->player.down = true;
	else if (key == 0x64)
		data->player.right = true;
	else if (key == 0xff1b)
		handle_close(data);
}

static void	move_player(int key, t_data *data)
{
	if (key == 0x77)
		data->player.up = true;
	else if (key == 0x61)
		data->player.left = true;
	else
		move_player_aux(key, data);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == 0xff51)
		data->player.rotate_r = true;
	else if (key == 0xff53)
		data->player.rotate_l = true;
	if (data->player.angle < 0)
		data->player.angle = PI * 2;
	else if (data->player.angle > PI * 2)
		data->player.angle = 0;
	else
		move_player(key, data);
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->graphics.mlx, data->textures.ea);
	mlx_destroy_image(data->graphics.mlx, data->textures.no);
	mlx_destroy_image(data->graphics.mlx, data->textures.so);
	mlx_destroy_image(data->graphics.mlx, data->textures.we);
	mlx_destroy_window(data->graphics.mlx, data->graphics.win);
	mlx_destroy_image(data->graphics.mlx, data->img.img);
	mlx_destroy_display(data->graphics.mlx);
	free(data->graphics.mlx);
	free_bf_exit(0, &data->map);
	return (0);
}
