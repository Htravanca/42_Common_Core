/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:48:11 by hepereir          #+#    #+#             */
/*   Updated: 2025/04/13 20:28:26 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ft to count commas of the colors code
static void	ft_count_comma(char *str, char *id, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && id[0] == 'F')
			map->aux.f_comma++;
		else if (str[i] == ',' && id[0] == 'C')
			map->aux.c_comma++;
		i++;
	}
	return ;
}

// ft to free the **colors after the split
static void	ft_free_colors(char **colors)
{
	int	i;

	i = 0;
	while (colors && colors[i])
	{
		free(colors[i]);
		i++;
	}
	free(colors);
}

// ft aux to put color in the right place
static void	ft_aux_color(char *id, int nb, int pos, t_map *map)
{
	if (id[0] == 'F')
		map->floor_color[pos] = nb;
	else if (id[0] == 'C')
		map->ceiling_color[pos] = nb;
}

// to to tranform string with colors into the data stuct
static void	ft_take_colors(char *id, char *str, t_map *map)
{
	char	**colors;
	char	*temp;
	int		nb;
	int		i;

	colors = ft_split(str, ',');
	i = 0;
	while (colors[i])
	{
		temp = ft_strtrim(colors[i], " ");
		if (!temp[0] || ft_isalldigit(temp) == -1 || i > 3)
			map->aux.wrong_rgb++;
		nb = ft_atoi(temp);
		if (nb < 0 || nb > 255)
			map->aux.wrong_rgb++;
		else
			ft_aux_color(id, nb, i, map);
		free(temp);
		i++;
	}
	if (i != 3)
		map->aux.wrong_rgb++;
	ft_free_colors(colors);
}

// ft extract colors, clean it, put in the struct
int	ft_colors(char *line, char *id, t_map *map)
{
	char	*temp;
	char	*trimmed;

	if (ft_iswhitespaces(line, id) == -1)
		return (-1);
	temp = ft_strdup(ft_strnstr(line, id, ft_strlen(line)) + 1);
	if (!temp)
		return (-1);
	trimmed = ft_strtrim(temp, " \n");
	free(temp);
	if (!trimmed)
		return (-1);
	ft_count_comma(trimmed, id, map);
	ft_take_colors(id, trimmed, map);
	free(trimmed);
	if (id[0] == 'F')
		map->aux.f_nb++;
	else if (id[0] == 'C')
		map->aux.c_nb++;
	return (0);
}
