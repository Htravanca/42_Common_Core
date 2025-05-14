/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:48:11 by hepereir          #+#    #+#             */
/*   Updated: 2025/04/13 22:12:31 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ft to check the textures files
int	ft_xpm(char *file)
{
	int	fd;
	int	pos;

	pos = 0;
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	while (file[pos] && file[pos] != '.')
		pos++;
	if (!(file[pos] == '.' && file[pos + 1] == 'x' && file[pos + 2] == 'p'
			&& file[pos + 3] == 'm' && file[pos + 4] == '\0'))
		return (-1);
	return (0);
}

// count the heigh of the map
static void	ft_count_map_line(char *line, t_map *map)
{
	static int	in_map;

	if (ft_line_map(line) || in_map == 1)
	{
		in_map = 1;
		map->map_height++;
	}
}

// ft to take the map height
int	ft_map_size(char *file, t_map *map)
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
		ft_count_map_line(getline, map);
		free(getline);
	}
	close(fd);
	return (0);
}
