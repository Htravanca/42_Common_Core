/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:39:50 by jalves-v          #+#    #+#             */
/*   Updated: 2025/05/07 12:56:06 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// draws the ceiling and floor colors above and below the wall
void	horizontal_planes(t_data *data, int x, int start_y, int end_y)
{
	int	y;
	int	floor;
	int	ceiling;

	y = 0;
	floor = get_hex(data->map.floor_color);
	ceiling = get_hex(data->map.ceiling_color);
	while (y < start_y)
	{
		draw_pixel(x, y, ceiling, data);
		y++;
	}
	y = end_y;
	while (y < HEIGHT)
	{
		draw_pixel(x, y, floor, data);
		y++;
	}
}

// calculates the horizontal texture coordinate (tex_x)
// based on the ray hit position and side
// it will define which vertical stripe of the texture will be used for each col
int	verify_side(t_data *data, float ray_x, float ray_y)
{
	float	wall_x;
	int		tex_x;

	tex_x = 0;
	if (data->wall.side == 0)
		wall_x = ray_y;
	else
		wall_x = ray_x;
	wall_x /= TILE_SIZE;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)64);
	if ((data->wall.side == 0 && ray_x < data->player.pos_x)
		|| (data->wall.side == 1 && ray_y > data->player.pos_y))
		tex_x = 64 - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= 64)
		tex_x = 64 - 1;
	return (tex_x);
}

static int	load_textures_aux(t_data *data)
{
	data->textures.no_img = mlx_get_data_addr(data->textures.no,
			&data->textures.bpp, &data->textures.line_sz,
			&data->textures.endian);
	data->textures.so_img = mlx_get_data_addr(data->textures.so,
			&data->textures.bpp, &data->textures.line_sz,
			&data->textures.endian);
	data->textures.we_img = mlx_get_data_addr(data->textures.we,
			&data->textures.bpp, &data->textures.line_sz,
			&data->textures.endian);
	data->textures.ea_img = mlx_get_data_addr(data->textures.ea,
			&data->textures.bpp, &data->textures.line_sz,
			&data->textures.endian);
	if (!data->textures.no_img || !data->textures.so_img
		|| !data->textures.we_img || !data->textures.ea_img)
		return (free_textures(data));
	return (0);
}

int	load_textures(t_data *data)
{
	int	width;
	int	height;

	data->textures.no = mlx_xpm_file_to_image(data->graphics.mlx,
			data->map.no_path, &width, &height);
	if (!data->textures.no)
		return (free_textures(data));
	data->textures.so = mlx_xpm_file_to_image(data->graphics.mlx,
			data->map.so_path, &width, &height);
	if (!data->textures.so)
		return (free_textures(data));
	data->textures.we = mlx_xpm_file_to_image(data->graphics.mlx,
			data->map.we_path, &width, &height);
	if (!data->textures.we)
		return (free_textures(data));
	data->textures.ea = mlx_xpm_file_to_image(data->graphics.mlx,
			data->map.ea_path, &width, &height);
	if (!data->textures.ea)
		return (free_textures(data));
	return (load_textures_aux(data));
}
