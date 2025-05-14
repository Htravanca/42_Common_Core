/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:25:22 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/05 19:57:39 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	static t_data	data;

	ft_parse(argc, argv, &data);
	if (init_game(&data) == -1)
		free_bf_exit(0, &data.map);
	if (load_textures(&data) == -1)
		free_bf_exit(0, &data.map);
	mlx_hook(data.graphics.win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.graphics.win, 3, 1L << 1, handle_keyrelease, &data);
	mlx_hook(data.graphics.win, 17, 0, handle_close, &data);
	mlx_loop_hook(data.graphics.mlx, raycasting, &data);
	mlx_loop(data.graphics.mlx);
	free_bf_exit(0, &data.map);
	return (0);
}
