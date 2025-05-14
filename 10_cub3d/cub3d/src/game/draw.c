/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:35:32 by jalves-v          #+#    #+#             */
/*   Updated: 2025/05/07 12:56:06 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// draws a single pixel at (x, y) with the given color to the image buffer
void	draw_pixel(int x, int y, int color, t_data *data)
{
	int		idx;
	char	*pixel;

	if (x >= WIDTH || y > HEIGHT || x < 0
		|| y < 0)
		return ;
	idx = (y * data->img.line_len) + (x * (data->img.bpp >> 3));
	pixel = data->img.addr + idx;
	*(int *)pixel = color;
}

// renders a vertical wall slice at column x using the given texture column
void	draw_walls(t_data *data, t_textures *tex, int x, int tex_x)
{
	float	step;
	float	tex_pos;
	int		tex_y;
	int		y;

	step = (float)TILE_SIZE / data->wall.height;
	if (data->wall.start_y < 0)
		tex_pos = -data->wall.start_y * step;
	else
		tex_pos = 0;
	tex->img = mlx_get_data_addr(data->wall.tex, &tex->bpp, &tex->line_sz,
			&tex->endian);
	if (data->wall.start_y < 0)
		y = 0;
	else
		y = data->wall.start_y;
	while (y < data->wall.end_y && y < HEIGHT)
	{
		tex_y = ((int)tex_pos) % TILE_SIZE;
		tex->color = get_pixel(data, tex->img, tex_x, tex_y);
		draw_pixel(x, y, tex->color, data);
		tex_pos += step;
		y++;
	}
}

// calculates wall projection and draws the textured wall slice for column x
void	draw_textures(t_data *data, int x, float ray_x, float ray_y)
{
	int	tex_x;

	data->wall.dist = fixed_dist(ray_x, ray_y, data);
	if (data->wall.dist < 0.001)
		data->wall.dist = 0.001;
	data->wall.height = (TILE_SIZE * HEIGHT) / (data->wall.dist
			* tan(FOV / 2));
	data->wall.start_y = (HEIGHT - data->wall.height) / 2;
	data->wall.end_y = data->wall.start_y + data->wall.height;
	tex_x = verify_side(data, ray_x, ray_y);
	horizontal_planes(data, x, data->wall.start_y, data->wall.end_y);
	draw_walls(data, &(data->textures), x, tex_x);
}

// selects the correct wall texture and draws it
static void	draw_aux(t_data *data, int x, float ray_x, float ray_y)
{
	if (data->wall.side == 0)
	{
		if (ray_x < data->player.pos_x)
			data->wall.tex = data->textures.ea;
		else
			data->wall.tex = data->textures.we;
	}
	else
	{
		if (ray_y < data->player.pos_y)
			data->wall.tex = data->textures.so;
		else
			data->wall.tex = data->textures.no;
	}
	draw_textures(data, x, ray_x, ray_y);
}

// performs raycasting to detect wall collision and
// triggers wall rendering for column x
int	draw(t_data *data, t_ray *ray, int x)
{
	int	map_x;
	int	map_y;

	ray_setup(ray, data, x);
	map_x = (int)data->player.pos_x;
	map_y = (int)data->player.pos_y;
	dir_dist(ray, data, map_x, map_y);
	while (data->map.map[map_y / TILE_SIZE][map_x / TILE_SIZE] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			map_x += ray->step_x;
			data->wall.side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			map_y += ray->step_y;
			data->wall.side = 1;
		}
	}
	draw_aux(data, x, map_x, map_y);
	return (0);
}
