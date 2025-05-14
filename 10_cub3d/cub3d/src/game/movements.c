/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:11:45 by jalves-v          #+#    #+#             */
/*   Updated: 2025/05/09 10:32:02 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_around(t_data *data)
{
	const float	angle_speed = 0.02;

	if (data->player.rotate_r)
		data->player.angle -= angle_speed;
	if (data->player.rotate_l)
		data->player.angle += angle_speed;
	if (data->player.angle > PI * 2)
		data->player.angle = 0.0;
	else if (data->player.angle < 0)
		data->player.angle = PI * 2;
}

static void	walk_aux2(t_data *data, float cos_angle, float sin_angle)
{
	const float	speed = 3;
	float		x;
	float		y;

	if (data->player.right)
	{
		x = data->player.pos_x - sin_angle * speed;
		y = data->player.pos_y + cos_angle * speed;
		if (!wall(x, y, data))
		{
			data->player.pos_x = x;
			data->player.pos_y = y;
		}
	}
}

static void	walk_aux(t_data *data, float cos_angle, float sin_angle)
{
	float		x;
	float		y;
	const float	speed = 3;

	if (data->player.down)
	{
		x = data->player.pos_x - cos_angle * speed;
		y = data->player.pos_y - sin_angle * speed;
		if (!wall(x, y, data))
		{
			data->player.pos_x = x;
			data->player.pos_y = y;
		}
	}
	if (data->player.left)
	{
		x = data->player.pos_x + sin_angle * speed;
		y = data->player.pos_y - cos_angle * speed;
		if (!wall(x, y, data))
		{
			data->player.pos_x = x;
			data->player.pos_y = y;
		}
	}
	walk_aux2(data, cos_angle, sin_angle);
}

void	walk(t_data *data)
{
	const float	speed = 3;
	const float	cos_angle = cos(data->player.angle);
	const float	sin_angle = sin(data->player.angle);
	float		x;
	float		y;

	if (data->player.up)
	{
		x = data->player.pos_x + cos_angle * speed;
		y = data->player.pos_y + sin_angle * speed;
		if (!wall(x, y, data))
		{
			data->player.pos_x = x;
			data->player.pos_y = y;
		}
	}
	walk_aux(data, cos_angle, sin_angle);
}

int	handle_keyrelease(int key, t_data *data)
{
	if (key == 0x77)
		data->player.up = false;
	if (key == 0x61)
		data->player.left = false;
	if (key == 0x73)
		data->player.down = false;
	if (key == 0x64)
		data->player.right = false;
	if (key == 0xff51)
		data->player.rotate_r = false;
	if (key == 0xff53)
		data->player.rotate_l = false;
	return (0);
}
