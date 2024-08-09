/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:59 by hepereir          #+#    #+#             */
/*   Updated: 2024/08/09 15:22:42 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = NULL;
	if (ft_map_parsing(argc, argv) || ft_init_map(argv[1], &game))
		return (0);
	if (ft_map_checker(&game))
		return (0);
	ft_game_start(&game);
	ft_free_map(game.map);
	return (0);
}
