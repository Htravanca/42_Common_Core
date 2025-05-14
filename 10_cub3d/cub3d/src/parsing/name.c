/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:22:21 by hepereir          #+#    #+#             */
/*   Updated: 2025/04/12 20:34:36 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// aux to map name
static int	ft_check_map_name(char *name)
{
	int	fd;
	int	pos;

	pos = 0;
	fd = open(name, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (-1);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	pos = ft_strlen(name);
	while (pos >= 0 && name[pos] != '.')
		pos--;
	if (!(name[pos] == '.' && name[pos + 1] == 'c' && name[pos + 2] == 'u'
			&& name[pos + 3] == 'b' && name[pos + 4] == '\0'))
		return (-1);
	return (0);
}

// ft to check if the name of the map is correct
void	ft_map_name(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_perror("Choose a map");
		exit(1);
	}
	else if (argc == 2)
	{
		if (ft_check_map_name(argv[1]) == -1)
		{
			ft_perror("Error opening map, choose a valid .cub file");
			exit(1);
		}
	}
	else if (argc >= 3)
	{
		ft_perror("Choose only a map");
		exit(1);
	}
	return ;
}
