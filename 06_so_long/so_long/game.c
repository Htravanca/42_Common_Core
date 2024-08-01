#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>

void cleanup_and_exit(t_game *game)
{
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

	mlx_key_hook(game->mlx.win_ptr, handle_input, game);
    mlx_loop(game->mlx.mlx_ptr);                                // Leave the control to the EVENT LOOP
    cleanup_and_exit(game);
}
