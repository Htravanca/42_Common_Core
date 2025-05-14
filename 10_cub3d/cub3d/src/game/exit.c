/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:02:36 by jalves-v          #+#    #+#             */
/*   Updated: 2025/05/01 15:40:13 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_mlx_ptr(t_data *data, bool destroy_img)
{
	mlx_destroy_window(data->graphics.mlx, data->graphics.win);
	if (destroy_img)
		mlx_destroy_image(data->graphics.mlx, data->img.img);
	mlx_destroy_display(data->graphics.mlx);
	free(data->graphics.mlx);
	return (-1);
}

int	free_textures(t_data *data)
{
	if (data->textures.no)
		mlx_destroy_image(data->graphics.mlx, data->textures.no);
	if (data->textures.so)
		mlx_destroy_image(data->graphics.mlx, data->textures.so);
	if (data->textures.ea)
		mlx_destroy_image(data->graphics.mlx, data->textures.ea);
	if (data->textures.we)
		mlx_destroy_image(data->graphics.mlx, data->textures.we);
	free_mlx_ptr(data, true);
	return (-1);
}
