/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:48:11 by hepereir          #+#    #+#             */
/*   Updated: 2025/04/25 17:37:40 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// recursive flood fill
void	ft_flood_fill(char **map_copy, int x, int y)
{
	char	c;

	if (y < 0 || map_copy[y] == NULL || x < 0
		|| x >= (int)ft_strlen(map_copy[y]))
	{
		map_copy[0][0] = 'X';
		return ;
	}
	c = map_copy[y][x];
	if (c == '1' || c == 'F')
		return ;
	if (c == ' ' || c == '\0')
	{
		map_copy[0][0] = 'X';
		return ;
	}
	map_copy[y][x] = 'F';
	ft_flood_fill(map_copy, x + 1, y);
	ft_flood_fill(map_copy, x - 1, y);
	ft_flood_fill(map_copy, x, y + 1);
	ft_flood_fill(map_copy, x, y - 1);
}

// if this part is walkable
static int	ft_walkable(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

// ft to free the cpy of the map
static void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

// ft to dup the map
static char	**ft_map_dup(char **map, int height)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = ft_calloc(height + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	cpy[height] = NULL;
	while (i < height)
	{
		cpy[i] = ft_strdup(map[i]);
		i++;
	}
	return (cpy);
}

// ft to check if map is closed by walls
int	ft_map_closed(t_map *map)
{
	int		y;
	int		x;
	char	**map_copy;
	int		rt;

	rt = 0;
	map_copy = ft_map_dup(map->map, map->map_height);
	if (!map_copy)
		return (-1);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (ft_walkable(map_copy[y][x]))
				ft_flood_fill(map_copy, x, y);
			x++;
		}
		y++;
	}
	if (map_copy[0][0] == 'X')
		rt = -1;
	ft_free_map(map_copy);
	return (rt);
}
