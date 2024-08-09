/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:18:44 by hepereir          #+#    #+#             */
/*   Updated: 2024/08/09 12:19:00 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_mlx_data
{
    void		*mlx_ptr;
    void		*win_ptr;
}               t_mlx_data;

typedef struct s_game
{
	char		**map;
	char		**img;
	int			map_width;
	int			map_heigth;
	int			collectible_count;
	int			collectible_found;
	int			exit_count;
	int			exit_found;
    int     	start_count;
    int			player_x;
	int			player_y;
	int			steps;
	t_mlx_data	mlx;
}				t_game;

//AUXILIAR PRINT
void	ft_print_map(char **map);
void	ft_print_struct(t_game *game);

//GAME
int		ft_pressed_x(t_game *game);
int 	ft_move(t_game *game, int x, int y);
int 	ft_check_movement(t_game *game, int x, int y);
int		ft_handle_input(int keysym, t_game *game);
void    ft_game_start(t_game *game);

//GAME2
void 	ft_game_cleanup(t_game *game);
void 	ft_init_images(t_game *game);
void	ft_map_visualizer(t_game *game);

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

//PARSING
int     ft_check_map_name(char *name);
int     ft_map_parsing(int argc, char **argv);
int     ft_map_lines(char *str);
int	 	ft_init_map(char *str, t_game *game);

#endif