#include "so_long.h"

void	ft_print_map(char **map)
{
	int i = 0;
	while (map[i] != NULL)
	{
		printf("[%d]:%s", i, map[i]);
		i++;
	}
	printf("[%d]:%s", i, map[i]);
	printf("\n\n");
}

void	ft_print_struct(t_game *game)
{
	ft_print_map(game->map);
	printf("map_width:\t\t%d\n",game->map_width);
	printf("map_heigth:\t\t%d\n",game->map_heigth);
	printf("collectible_count:\t%d\n",game->collectible_count);
	printf("exit_count:\t\t%d\n",game->exit_count);
	printf("start_count:\t\t%d\n",game->start_count);
	printf("player_x:\t\t%d\n",game->player_x);
	printf("player_y:\t\t%d\n",game->player_y);
}

int main(int argc, char **argv)
{
	t_game game;

	game.map = NULL;
	if (ft_map_parsing(argc, argv) || ft_check_map(argv[1], &game)) //confirma que o ficheiro existe e da para abrir e é um .ber
		return (0);													//abre o ficheiro e cria com malloc um array 2D com o mapa 
	ft_map_checker(&game);											//verifica um mapa valido
	ft_print_struct(&game);											//print dados
	
				
}
