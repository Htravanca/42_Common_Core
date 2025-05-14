/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:12:35 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/09 10:33:51 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <math.h>
# include <stdbool.h>

# define PI 3.14159265
# define TILE_SIZE 64
# define FOV 1.047197551
# define WIDTH 1280
# define HEIGHT 720

typedef struct s_aux_map
{
	int			no_nb;
	int			so_nb;
	int			we_nb;
	int			ea_nb;
	int			f_nb;
	int			f_comma;
	int			c_nb;
	int			c_comma;
	int			wrong_rgb;
	int			map_error;
}				t_aux_map;

typedef struct s_wall
{
	int			side;
	int			start_y;
	int			end_y;
	float		height;
	float		dist;
	void		*tex;
}				t_wall;

typedef struct s_ray
{
	float		cos_angle;
	float		sin_angle;
	float		ray_dir_x;
	float		ray_dir_y;
	float		delta_x;
	float		delta_y;
	float		side_dist_x;
	float		side_dist_y;
	int			step_x;
	int			step_y;
}				t_ray;

typedef struct s_map
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			floor_color[3];
	int			ceiling_color[3];
	char		**map;
	int			map_width;
	int			map_height;
	int			screen_height;
	int			screen_width;
	t_aux_map	aux;
}				t_map;

typedef struct s_player
{
	float		pos_x;
	float		pos_y;
	float		angle;
	bool		up;
	bool		down;
	bool		left;
	bool		right;
	bool		rotate_r;
	bool		rotate_l;
}				t_player;

typedef struct s_graph
{
	void		*img;
	void		*mlx;
	void		*win;
	int			line_size;
	int			endian;
	int			bpp;
	char		*data;
}				t_graph;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_textures
{
	void		*no;
	void		*so;
	void		*we;
	void		*ea;
	void		*img;
	char		*no_img;
	char		*ea_img;
	char		*so_img;
	char		*we_img;
	int			bpp;
	int			line_sz;
	int			endian;
	int			color;
}				t_textures;

typedef struct s_data
{
	t_map		map;
	t_graph		graphics;
	t_player	player;
	t_textures	textures;
	t_wall		wall;
	t_ray		ray;
	t_img		img;
}				t_data;

// AUX
void			ft_print_struct(t_map *map, t_player *player);
void			ft_perror(char *msg);
void			free_bf_exit(int error, t_map *map);

// COLORS
int				ft_colors(char *line, char *id, t_map *map);

// MAP SIZE
int				ft_xpm(char *file);
int				ft_map_size(char *file, t_map *map);

// MAP
int				ft_line_map(char *getline);
int				ft_cpy_map(char *file, t_map *map);
void			ft_clean_map(t_map *map);

// MAP2
void			ft_width_map(t_map *map);
int				ft_one_player(t_map *map);
void			ft_player(t_map *map, t_player *player);

// MAP3
int				ft_map_closed(t_map *map);

// NAME
void			ft_map_name(int argc, char **argv);

// PARSE
void			ft_parse(int argc, char **argv, t_data *data);

// TEXTURE
int				ft_iswhitespaces(char *line, char *id);
int				ft_first_part(char *file, t_map *map);

/*******************************************/

// handle_game
int				raycasting(t_data *data);
int				init_game(t_data *data);
int				handle_keypress(int key, t_data *data);
int				handle_close(t_data *data);

// raycasting
int				raycasting(t_data *data);
void			draw_pixel(int x, int y, int color, t_data *data);
int				load_textures(t_data *data);
void			ray_setup(t_ray *ray, t_data *data, int x);
void			dir_dist(t_ray *ray, t_data *data, int map_x, int map_y);

// raycasting_aux
float			fixed_dist(float x2, float y2, t_data *data);
int				wall(float px, float py, t_data *data);
void			clear_window(t_data *data);
int				get_hex(int *rgb);
int				get_pixel(t_data *data, char *img, int x, int y);

// draw
int				draw(t_data *data, t_ray *ray, int x);
void			draw_pixel(int x, int y, int color, t_data *data);
void			draw_textures(t_data *data, int x, float ray_x, float ray_y);

// draw2
void			horizontal_planes(t_data *data, int x, int start_y, int end_y);
int				verify_side(t_data *data, float ray_x, float ray_y);

// movements
int				handle_keyrelease(int key, t_data *data);
void			walk(t_data *data);
void			look_around(t_data *data);

// exit
int				free_mlx_ptr(t_data *data, bool destroy_img);
int				free_textures(t_data *data);

#endif
