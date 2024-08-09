/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:23:46 by hepereir          #+#    #+#             */
/*   Updated: 2024/08/09 15:23:47 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("[%d]:%s", i, map[i]);
		i++;
	}
	printf("[%d]:%s", i, map[i]);
	printf("\n\n");
}

void	ft_print_struct(t_game *game)
{
	ft_print_map(game->map);
	printf("map_width:\t\t%d\n", game->map_width);
	printf("map_heigth:\t\t%d\n", game->map_heigth);
	printf("collectible_count:\t%d\n", game->collectible_count);
	printf("collectible_found:\t%d\n", game->collectible_found);
	printf("exit_count:\t\t%d\n", game->exit_count);
	printf("exit_found:\t\t%d\n", game->exit_found);
	printf("start_count:\t\t%d\n", game->start_count);
	printf("player_x:\t\t%d\n", game->player_x);
	printf("player_y:\t\t%d\n", game->player_y);
	printf("steps:\t\t%d\n", game->steps);
}
