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
	int		collectible_found;
	int		exit_count;
	int		exit_found;
    int     start_count;
    int		player_x;
	int		player_y;
}			t_game;

//AUXILIAR PRINT
void	ft_print_map(char **map);
void	ft_print_struct(t_game *game);

//PARSING
int     ft_map_parsing(int argc, char **argv);
int     ft_check_map_name(char *name);
int     ft_map_lines(char *str);
int	 	ft_check_map(char *str, t_game *game);

//MAP CHECKER
int     ft_strlen_map(char *line);
int 	ft_map_square(t_game *game);
int		ft_wall_map(t_game *game);
int     ft_map_checker(t_game *game);

//MAP CHECKER 2
void 	ft_count_stuff(t_game *game);
void 	ft_dfs(t_game *game, char **map, int y, int x);
void    ft_free_map(char **map_temp);
int 	ft_check_initial(t_game *game);

#endif