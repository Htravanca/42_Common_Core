/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:48:11 by hepereir          #+#    #+#             */
/*   Updated: 2025/04/13 20:28:14 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ft to check if the line bf the id is only whitespaces
int	ft_iswhitespaces(char *line, char *id)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (id[j] && line[i] && line[i] == id[j])
	{
		i++;
		j++;
	}
	if (id[j] != '\0')
		return (-1);
	return (0);
}

// ft extract texture, clean it, put in the struct
static int	ft_texture(char *line, char *id, char **dest, int *aux)
{
	char	*temp;
	char	*trimmed;

	if (ft_iswhitespaces(line, id) == -1)
		return (-1);
	temp = ft_strdup(ft_strnstr(line, id, ft_strlen(line)) + 2);
	if (!temp)
		return (-1);
	trimmed = ft_strtrim(temp, " \n");
	free(temp);
	if (!trimmed)
		return (-1);
	free(*dest);
	*dest = trimmed;
	(*aux)++;
	return (0);
}

// check if the line is only composed by spaces or \n
static int	ft_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] && (line[i] != ' ') && (line[i] != '\n'))
			return (1);
		i++;
	}
	return (0);
}

// search for the info in the string and put it in the struct
static int	ft_search_line(char *line, t_map *map)
{
	int			rt;
	static int	flag;

	rt = 0;
	if (ft_strnstr(line, "NO", ft_strlen(line)) != NULL && flag == 0)
		rt = ft_texture(line, "NO", &map->no_path, &map->aux.no_nb);
	else if (ft_strnstr(line, "SO", ft_strlen(line)) != NULL && flag == 0)
		rt = ft_texture(line, "SO", &map->so_path, &map->aux.so_nb);
	else if (ft_strnstr(line, "WE", ft_strlen(line)) != NULL && flag == 0)
		rt = ft_texture(line, "WE", &map->we_path, &map->aux.we_nb);
	else if (ft_strnstr(line, "EA", ft_strlen(line)) != NULL && flag == 0)
		rt = ft_texture(line, "EA", &map->ea_path, &map->aux.ea_nb);
	else if (ft_strnstr(line, "F", ft_strlen(line)) != NULL && flag == 0)
		rt = ft_colors(line, "F", map);
	else if (ft_strnstr(line, "C", ft_strlen(line)) != NULL && flag == 0)
		rt = ft_colors(line, "C", map);
	else if (ft_empty_line(line) && ft_line_map(line) == 0)
		rt = -1;
	else if (ft_line_map(line) == 1)
		flag = 1;
	return (rt);
}

// ft to take textures and colors
int	ft_first_part(char *file, t_map *map)
{
	char	*getline;
	int		fd;

	getline = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_perror("Failed to open Map!");
		exit(1);
	}
	while (1)
	{
		getline = get_next_line(fd);
		if (getline == NULL)
			break ;
		if (ft_search_line(getline, map) == -1)
			map->aux.map_error++;
		free(getline);
	}
	close(fd);
	return (0);
}
