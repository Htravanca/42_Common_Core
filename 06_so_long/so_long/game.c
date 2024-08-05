#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>

void ft_game_cleanup(t_game *game)
{
    int i;

    i = 0;
    if(game->img != NULL)
    {
        while (i < 5)
        {
            if (game->img[i] != NULL)
                mlx_destroy_image(game->mlx.mlx_ptr, game->img[i]);
            i++;
        }
        free(game->img);
    }
    if (game->mlx.win_ptr != NULL)
        mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
    if (game->mlx.mlx_ptr != NULL)
    {
        mlx_destroy_display(game->mlx.mlx_ptr);
        free(game->mlx.mlx_ptr);
    }
}

int	handle_input(int keysym, t_game *game)
{
    if (keysym == XK_Up || keysym == XK_w)
    {
        printf("The %d Up key has been pressed\n\n", keysym);
    }
    else if (keysym == XK_Down || keysym == XK_s)
    {
        printf("The %d Down key has been pressed\n\n", keysym);
    }
    else if (keysym == XK_Right || keysym == XK_d)
    {
        printf("The %d Right key has been pressed\n\n", keysym);
    }
    else if (keysym == XK_Left || keysym == XK_a)
    {
        printf("The %d Left key has been pressed\n\n", keysym);
    }
    else if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_loop_end(game->mlx.mlx_ptr);
        return (1);
    }
    else
        printf("The %d key has been pressed\n\n", keysym);
    return (0);
} 

void ft_init_images(t_game *game)
{
    int	i;

	i = 0;
	game->img = malloc(5 * sizeof(void *));
	if (!game->img)
		return ;
	game->img[0] = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "imagens/collect.xpm", &i, &i);
	game->img[1] = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "imagens/exit.xpm", &i, &i);
	game->img[2] = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "imagens/floor.xpm", &i, &i);
	game->img[3] = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "imagens/player.xpm", &i, &i);
	game->img[4] = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "imagens/wall.xpm", &i, &i);
}

void	ft_map_visualizer(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{   
            if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->img[2], x * 32, y * 32);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->img[4], x * 32, y * 32);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->img[3], x * 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->img[0], x * 32, y * 32);
            else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->img[1], x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void    ft_game_start(t_game *game)
{
    game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
        return ;
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, game->map_width * 32, game->map_heigth * 32, "So Long!");
	if (game->mlx.win_ptr == NULL)
    {
        mlx_destroy_display(game->mlx.mlx_ptr);
        free(game->mlx.mlx_ptr);
        return ;
    }

    ft_init_images(game);
    ft_map_visualizer(game);

	mlx_key_hook(game->mlx.win_ptr, handle_input, game);
    mlx_loop(game->mlx.mlx_ptr);                                // Leave the control to the EVENT LOOP
    ft_game_cleanup(game);
}
