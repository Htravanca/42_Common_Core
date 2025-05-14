/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:52:57 by hepereir          #+#    #+#             */
/*   Updated: 2025/04/13 22:14:45 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ft to free everything before exit program
void	free_bf_exit(int error, t_map *map)
{
	int	i;

	i = 0;
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
	while (map->map && map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	if (map->map)
		free(map->map);
	exit(error);
}

// ft print map
static void	ft_map_print(t_map *map)
{
	int	i;

	i = 0;
	while (map->map && map->map[i])
	{
		printf("<%s>\n", map->map[i]);
		i++;
	}
}

// ft to print the map struct
void	ft_print_struct(t_map *map, t_player *player)
{
	printf("NO:\t<%s>\n", map->no_path);
	printf("SO:\t<%s>\n", map->so_path);
	printf("WE:\t<%s>\n", map->we_path);
	printf("EA:\t<%s>\n", map->ea_path);
	printf("floor:\t<%d> <%d> <%d>\n", map->floor_color[0], map->floor_color[1],
		map->floor_color[2]);
	printf("ceil:\t<%d> <%d> <%d>\n", map->ceiling_color[0],
		map->ceiling_color[1], map->ceiling_color[2]);
	printf("no nb\t%d\n", map->aux.no_nb);
	printf("so nb\t%d\n", map->aux.so_nb);
	printf("we nb\t%d\n", map->aux.we_nb);
	printf("ea nb\t%d\n", map->aux.ea_nb);
	printf("f nb\t%d\n", map->aux.f_nb);
	printf("f comma\t%d\n", map->aux.f_comma);
	printf("c nb\t%d\n", map->aux.c_nb);
	printf("c comma\t%d\n", map->aux.c_comma);
	printf("RGB error\t%d\n", map->aux.wrong_rgb);
	printf("Map errors\t%d\n", map->aux.map_error);
	printf("Height\t%d\n", map->map_height);
	printf("width\t%d\n", map->map_width);
	ft_map_print(map);
	printf("Pos X\t%f\n", player->pos_x);
	printf("Pos Y\t%f\n", player->pos_y);
	printf("Angle\t%f\n", player->angle);
}

// ft to print the error
void	ft_perror(char *msg)
{
	printf("\033[1;31mError\033[0m\n");
	printf("\033[1;31m%s\033[0m\n", msg);
	return ;
}
