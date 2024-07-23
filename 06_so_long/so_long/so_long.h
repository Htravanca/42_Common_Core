#ifndef SO_LONG_H
# define SO_LONG_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game
{
	char	**map;
	int		map_width;
	int		map_heigth;
	int		collectible_count;
	int		exit_count;
    int     start_count;
    int		player_x;
	int		player_y;
}			t_game;

//PARSING
int     ft_map_parsing(int argc, char **argv);
int     ft_check_map_name(char *name);
int     ft_map_lines(char *str);
char    **ft_check_map(char *str);

//MAP CHECKER
int     ft_strlen_map(char *line);
int     ft_map_square(char **map);
int     ft_wall_map(char **map);
int     ft_map_checker(char **map);


#endif