/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:51 by hepereir          #+#    #+#             */
/*   Updated: 2024/09/11 22:18:56 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_stuff(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'C')
				game->collectible_count++;
			if (game->map[i][j] == 'E')
				game->exit_count++;
			if (game->map[i][j] == 'P')
			{
				game->start_count++;
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
}

static void	ft_dfs(t_game *game, char **map, int y, int x)
{
	if (y < 0 || y >= game->map_heigth || x < 0 || x >= game->map_width
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		game->exit_found++;
		map[y][x] = '1';
		return ;
	}
	if (map[y][x] != '1')
	{
		if (map[y][x] == 'C')
			game->collectible_found++;
		map[y][x] = 'V';
	}
	ft_dfs(game, map, y, x + 1);
	ft_dfs(game, map, y, x - 1);
	ft_dfs(game, map, y + 1, x);
	ft_dfs(game, map, y - 1, x);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_check_initial(t_game *game)
{
	char	**map_temp;
	int		i;

	i = 0;
	if (game->exit_count != 1 || game->start_count != 1)
		return (1);
	map_temp = malloc((game->map_heigth + 1) * sizeof(char *));
	while (i < game->map_heigth)
	{
		map_temp[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_temp[i] = NULL;
	ft_dfs(game, map_temp, game->player_y, game->player_x);
	ft_free_map(map_temp);
	if (game->collectible_count < 1
		|| game->collectible_found != game->collectible_count
		|| game->exit_found != game->exit_count)
		return (1);
	return (0);
}
