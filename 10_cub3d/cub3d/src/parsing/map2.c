/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:20:58 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/05 19:33:21 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ft to calculate map width
void	ft_width_map(t_map *map)
{
	int		i;
	size_t	prev;

	prev = 0;
	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) > prev)
			prev = ft_strlen(map->map[i]);
		i++;
	}
	map->map_width = prev;
	return ;
}

// ft to complete angle in palyer struct
static void	ft_player_angle(char var, t_player *player)
{
	if (var == 'S')
		player->angle = PI / 2;
	else if (var == 'W')
		player->angle = PI;
	else if (var == 'N')
		player->angle = (3 * PI) / 2;
	else if (var == 'E')
		player->angle = 0;
}

// ft to check if the map is only one player
int	ft_one_player(t_map *map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map->map && map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (-1);
	return (0);
}

// ft to find a player in the map and complete the struct
void	ft_player(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				player->pos_x = j * TILE_SIZE;
				player->pos_y = i * TILE_SIZE;
				ft_player_angle(map->map[i][j], player);
				break ;
			}
			j++;
		}
		i++;
	}
	return ;
}
