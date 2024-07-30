#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>

int	handle_input(int keysym, t_mlx_data *data)
{
    if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    printf("The %d key has been pressed\n\n", keysym);
    return (0);
} 

void    ft_game_start(t_game *game)
{
    game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
        return ;
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, 800, 600, "Game!");
	if (game->mlx.win_ptr == NULL)
    {
        mlx_destroy_display(game->mlx.mlx_ptr);
        free(game->mlx.mlx_ptr);
        return ;
    }

	mlx_key_hook(game->mlx.win_ptr, handle_input, &game->mlx);

    // Leave the control to the EVENT LOOP
    mlx_loop(game->mlx.mlx_ptr);

    free(game->mlx.mlx_ptr);
}
