/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:54 by hepereir          #+#    #+#             */
/*   Updated: 2024/09/12 17:58:48 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_map_name(char *name)
{
	int	fd;
	int	pos;
	char *buffer;

	pos = 0;
	buffer = NULL;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (1);
	while (name[pos] != '.')
		pos++;
	if (!(name[pos] == '.' && name[pos + 1] == 'b' && name[pos + 2] == 'e'
			&& name[pos + 3] == 'r' && name[pos + 4] == '\0'))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_map_parsing(int argc, char **argv)
{
	if (argc == 1)
	{
		perror("Error\nChoose a map");
		return (1);
	}
	else if (argc == 2)
	{
		if (ft_check_map_name(argv[1]))
		{
			perror("Error\nError opening map, choose a valid .ber file");
			return (1);
		}
	}
	else if (argc >= 3)
	{
		perror("Error\nChoose only a map");
		return (1);
	}
	return (0);
}

static int	ft_map_lines(char *str)
{
	int		lines;
	char	*getline;
	int		fd;

	lines = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nOpening map, choose a valid .ber file");
		return (1);
	}
	while (1)
	{
		getline = get_next_line(fd);
		if (getline == NULL)
			break ;
		lines++;
		free(getline);
		getline = NULL;
	}
	close(fd);
	return (lines);
}

static int	ft_write_map(t_game *game, int fd)
{
	int	i;

	i = 0;
	while (i < game->map_heigth)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			break ;
		i++;
	}
	game->map[i] = NULL;
	if (i != game->map_heigth)
		return (1);
	return (0);
}

int	ft_init_map(char *str, t_game *game)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nCan't open the map file");
		return (1);
	}
	game->map_heigth = ft_map_lines(str);
	if (game->map_heigth == 0)
	{
		perror("Error\nError opening map, choose a valid .ber file");
		close(fd);
		return (1);
	}
	game->map = malloc((game->map_heigth + 1) * sizeof(char *));
	if (game->map == NULL || ft_write_map(game, fd))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
