#include "so_long.h"

void ft_count_stuff(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == 'C')
                game->collectible_count++;
            if (game->map[i][j] == 'E')
                game->exit_count++;          
            if (game->map[i][j] == 'P')
            {
                game->start_count++;
                game->player_x = j;
                game->player_y = i;
            }
            j++;
        }
        i++;
    }
}

int ft_check_initial(t_game *game)
{
    if (game->exit_count != 1 || game->start_count != 1)
        return (1);
    
    return (0);
}