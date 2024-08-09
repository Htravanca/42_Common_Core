/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:47 by hepereir          #+#    #+#             */
/*   Updated: 2024/08/09 16:00:14 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_map(char *line)
{
	int	j;
	int	valid;

	j = 0;
	valid = 0;
	while (line[j])
	{
		if (line[j] == '0' || line[j] == '1' || line[j] == 'C' || line[j] == 'E'
			|| line[j] == 'P')
			valid++;
		j++;
	}
	if (line[j - 1] == '\n')
		j--;
	if (j != valid)
		return (0);
	return (j);
}

int	ft_map_square(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen_map(game->map[i]);
	i++;
	while (game->map[i] && ft_strlen_map(game->map[i]) == game->map_width)
		i++;
	if (game->map[i] != NULL)
		return (1);
	return (0);
}

int	ft_wall_map(t_game *game)
{
	int	j;
	int	len;
	int	i;

	i = 0;
	j = 0;
	while (game->map[0][j])
	{
		if (game->map[0][j] != '1' && game->map[0][j + 1] != '\0')
			return (1);
		j++;
	}
	j = 1;
	len = game->map_width - 1;
	while (game->map[j])
	{
		if (game->map[j][0] != '1' || game->map[j][len] != '1')
			return (1);
		j++;
	}
	j--;
	while (game->map[j][i])
		if (game->map[j][i++] != '1')
			return (1);
	return (0);
}

int	ft_map_checker(t_game *game)
{
	game->collectible_count = 0;
	game->exit_count = 0;
	game->start_count = 0;
	game->collectible_found = 0;
	game->exit_found = 0;
	game->steps = 0;
	if (ft_map_square(game) || ft_wall_map(game))
	{
		perror("Erro: mapa não é quadrado ou nao esta fechado por paredes");
		return (1);
	}
	ft_count_stuff(game);
	if (ft_check_initial(game))
	{
		perror("Erro: elementos errados ou inacessiveis");
		return (1);
	}
	return (0);
}
