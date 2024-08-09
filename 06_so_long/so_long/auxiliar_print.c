/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:23:46 by hepereir          #+#    #+#             */
/*   Updated: 2024/08/09 16:07:55 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("[%d]:%s", i, map[i]);
		i++;
	}
	ft_printf("[%d]:%s", i, map[i]);
	ft_printf("\n\n");
}

void	ft_print_struct(t_game *game)
{
	ft_print_map(game->map);
	ft_printf("map_width:\t\t%d\n", game->map_width);
	ft_printf("map_heigth:\t\t%d\n", game->map_heigth);
	ft_printf("collectible_count:\t%d\n", game->collectible_count);
	ft_printf("collectible_found:\t%d\n", game->collectible_found);
	ft_printf("exit_count:\t\t%d\n", game->exit_count);
	ft_printf("exit_found:\t\t%d\n", game->exit_found);
	ft_printf("start_count:\t\t%d\n", game->start_count);
	ft_printf("player_x:\t\t%d\n", game->player_x);
	ft_printf("player_y:\t\t%d\n", game->player_y);
	ft_printf("steps:\t\t%d\n", game->steps);
}
