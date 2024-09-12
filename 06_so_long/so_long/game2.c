/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:42 by hepereir          #+#    #+#             */
/*   Updated: 2024/09/12 18:35:06 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_cleanup(t_game *game)
{
	int	i;

	i = 0;
	if (game->img != NULL)
	{
		while (i < 5)
		{
			if (game->img[i] != NULL)
				mlx_destroy_image(game->mlx.mlx_ptr, game->img[i]);
			i++;
		}
		free(game->img);
	}
	if (game->mlx.win_ptr != NULL)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	}
	if (game->mlx.mlx_ptr != NULL)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
	}
}

int	ft_init_images(t_game *game)
{
	int	i;

	i = 0;
	game->img = malloc(5 * sizeof(void *));
	if (!game->img)
		return (1);
	game->img[0] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"imagens/collect.xpm", &i, &i);
	game->img[1] = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "imagens/exit.xpm",
			&i, &i);
	game->img[2] = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "imagens/floor.xpm",
			&i, &i);
	game->img[3] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"imagens/player.xpm", &i, &i);
	game->img[4] = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "imagens/wall.xpm",
			&i, &i);
	if (game->img[0] == NULL || game->img[1] == NULL || game->img[2] == NULL
		|| game->img[3] == NULL || game->img[4] == NULL)
	{
		perror("Error\nError loading images");
		return (1);
	}
	return (0);
}

static void	ft_put_img(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img[2], x * 32, y * 32);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img[4], x * 32, y * 32);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img[3], x * 32, y * 32);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img[0], x * 32, y * 32);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img[1], x * 32, y * 32);
}

void	ft_map_visualizer(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	if (!game || !game->map || !game->img)
	{
		perror("Error\nCan't load the imgs");
		return ;
	}
	mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			ft_put_img(game, y, x);
			x++;
		}
		y++;
	}
}

int	ft_screen_size(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	mlx_get_screen_size(game->mlx.mlx_ptr, &width, &height);
	if ((game->map_width * 32) > width || (game->map_heigth * 32) > height)
	{
		perror("Error\nMap is bigger than your screen");
		return (1);
	}
	return (0);
}
