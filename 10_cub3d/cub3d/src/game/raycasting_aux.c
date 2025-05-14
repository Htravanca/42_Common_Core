/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:54:33 by jalves-v          #+#    #+#             */
/*   Updated: 2025/05/07 12:56:06 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// calculates the adjusted distance from the player to a point (x2, y2)
// according to the player's angle
float	fixed_dist(float x2, float y2, t_data *data)
{
	const float	delta_x = x2 - data->player.pos_x;
	const float	delta_y = y2 - data->player.pos_y;
	const float	angle = atan2(delta_y, delta_x) - data->player.angle;
	const float	fix_dist = sqrt(delta_x * delta_x + delta_y * delta_y)
		* cos(angle);

	return (fix_dist);
}

int	wall(float px, float py, t_data *data)
{
	const int	x = px / 64;
	const int	y = py / 64;

	if (data->map.map[y][x] == '1')
		return (1);
	return (0);
}

void	clear_window(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(x, y, 0, data);
			x++;
		}
		y++;
	}
}

// converts RGB values into a hexadecimal color
int	get_hex(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

// retrieves the color value of a pixel at (x, y) from an image buffer
int	get_pixel(t_data *data, char *img, int x, int y)
{
	return (*(int *)(img + (y * data->textures.line_sz + x * (data->textures.bpp
				/ 8))));
}
