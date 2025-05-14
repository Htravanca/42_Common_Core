/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:48:11 by hepereir          #+#    #+#             */
/*   Updated: 2025/04/13 22:12:37 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check if this line is still part of map
// return: 0->not part of map, 1->map
int	ft_line_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' '
			&& line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

// copy all the map
static void	ft_line(char *getline, t_map *map)
{
	static int	in_map;
	static int	map_line;

	if (ft_line_map(getline) || in_map == 1)
	{
		in_map = 1;
		map->map[map_line] = ft_strdup(getline);
		map_line++;
	}
}

// ft to copy the map to the struct
int	ft_cpy_map(char *file, t_map *map)
{
	char	*getline;
	int		fd;

	getline = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_perror("Failed to open Map!");
		free_bf_exit(1, map);
	}
	while (1)
	{
		getline = get_next_line(fd);
		if (getline == NULL)
			break ;
		ft_line(getline, map);
		free(getline);
	}
	close(fd);
	return (0);
}

// ft to clean the map parsed, take off unnessesary ' '
static void	ft_clean_map2(t_map *map)
{
	int		i;
	int		j;
	int		k;
	char	*temp2;

	i = 0;
	while (map->map && map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			k = j;
			while (map->map[i][k] && map->map[i][k] == ' ')
				k++;
			if (map->map[i][k] == '\0')
			{
				temp2 = ft_strndup(map->map[i], j);
				free(map->map[i]);
				map->map[i] = temp2;
				break ;
			}
			j++;
		}
		i++;
	}
}

// ft to clean the map parsed, take off '\n'
void	ft_clean_map(t_map *map)
{
	int		i;
	char	*temp;

	i = 0;
	while (map->map && map->map[i])
	{
		temp = ft_strtrim(map->map[i], "\n");
		free(map->map[i]);
		map->map[i] = temp;
		i++;
	}
	ft_clean_map2(map);
}
