/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:53:30 by jalves-v          #+#    #+#             */
/*   Updated: 2025/05/07 12:55:52 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// returns the appropriate wall texture based on ray direction
t_img	*get_wall_texture(t_data *data, float ray_dx, float ray_dy)
{
	if (fabs(ray_dx) > fabs(ray_dy))
	{
		if (ray_dx > 0)
			return (data->textures.we);
		else
			return (data->textures.ea);
	}
	else
	{
		if (ray_dy > 0)
			return (data->textures.no);
		else
			return (data->textures.so);
	}
}

// initialises ray direction and delta distances for a given screen column
void	ray_setup(t_ray *ray, t_data *data, int x)
{
	float	camera_x;
	float	ray_ang;

	camera_x = (2.0f * x / WIDTH) - 1.0f;
	ray_ang = data->player.angle + atan(camera_x * tan(FOV / 2));
	ray->cos_angle = cos(ray_ang);
	ray->sin_angle = sin(ray_ang);
	ray->ray_dir_x = ray->cos_angle;
	ray->ray_dir_y = ray->sin_angle;
	ray->delta_x = fabs(1 / ray->ray_dir_x);
	ray->delta_y = fabs(1 / ray->ray_dir_y);
}

// calculates step direction and initial side distances for DDA algorithm
// step direction defines if the ray moves right left up or down
// side distance is the distance the ray will run until it hits a line
// in the grid, either horizontal or vertical
void	dir_dist(t_ray *ray, t_data *data, int map_x, int map_y)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.pos_x - map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (map_x + 1.0 - data->player.pos_x) * ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.pos_y - map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map_y + 1.0 - data->player.pos_y) * ray->delta_y;
	}
}

// main function that performs raycasting column by column across the screen
int	raycasting(t_data *data)
{
	int	x;

	clear_window(data);
	x = 0;
	look_around(data);
	walk(data);
	while (x < WIDTH)
	{
		draw(data, &data->ray, x);
		x++;
	}
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->img.img, 0, 0);
	return (0);
}
