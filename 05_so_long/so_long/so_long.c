/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:59 by hepereir          #+#    #+#             */
/*   Updated: 2024/08/30 16:53:24 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = NULL;
	game.img = NULL;
	if (ft_map_parsing(argc, argv))
		return (0);
	if (ft_init_map(argv[1], &game) || ft_map_checker(&game))
	{
		ft_free_map(game.map);
		return (0);
	}
	ft_game_start(&game);
	ft_free_map(game.map);
	return (0);
}
