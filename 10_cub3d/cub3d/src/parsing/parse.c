/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:48:11 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/01 16:03:42 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ft to make all the check after the first part
static void	ft_check_fp(t_map *map)
{
	if (map->aux.no_nb != 1 || map->aux.so_nb != 1 || map->aux.we_nb != 1
		|| map->aux.ea_nb != 1)
		return (ft_perror("Invalid number of textures, check for duplicates"
				" or missing textures!"), free_bf_exit(1, map));
	if (ft_xpm(map->no_path) == -1 || ft_xpm(map->so_path) == -1
		|| ft_xpm(map->we_path) == -1 || ft_xpm(map->ea_path) == -1)
		return (ft_perror("Invalid textures!"), free_bf_exit(1, map));
	if (map->aux.f_nb != 1 || map->aux.c_nb != 1)
		return (ft_perror("Invalid number of colors, check for duplicates"
				" or missing colors!"), free_bf_exit(1, map));
	if (map->aux.wrong_rgb != 0 || map->aux.f_comma != 2
		|| map->aux.c_comma != 2)
		return (ft_perror("Invalid RGB code!"), free_bf_exit(1, map));
	if (map->aux.map_error > 0)
		return (ft_perror("Invalid characters"
				" in the file!"), free_bf_exit(1, map));
}

// ft to make all the check after the second part
static void	ft_check_sp(t_map *map)
{
	if (!map->map[0])
		return (ft_perror("Invalid map!"), free_bf_exit(1, map));
	else if (ft_one_player(map) == -1)
		return (ft_perror("Invalid map, check for missing or duplicate"
				" player start position!"), free_bf_exit(1, map));
	else if (ft_map_closed(map) == -1)
		return (ft_perror("Invalid map, "
				"map is not closed by walls!"), free_bf_exit(1, map));
}

// ft to init the parse
void	ft_parse(int argc, char **argv, t_data *data)
{
	ft_map_name(argc, argv);
	ft_first_part(argv[1], &data->map);
	ft_check_fp(&data->map);
	ft_map_size(argv[1], &data->map);
	data->map.map = ft_calloc(data->map.map_height + 1, sizeof(char *));
	if (!data->map.map)
	{
		ft_perror("Failed to allocate memory for map!");
		free_bf_exit(1, &data->map);
	}
	data->map.map[data->map.map_height] = NULL;
	ft_cpy_map(argv[1], &data->map);
	ft_clean_map(&data->map);
	ft_check_sp(&data->map);
	ft_width_map(&data->map);
	ft_player(&data->map, &data->player);
	return ;
}
