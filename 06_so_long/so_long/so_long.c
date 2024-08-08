#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	game.map = NULL;
	if (ft_map_parsing(argc, argv) || ft_init_map(argv[1], &game)) //confirma que o ficheiro existe e da para abrir e é um .ber
		return (0);
	if (ft_map_checker(&game))										//abre o ficheiro e cria com malloc um array 2D com o mapa 
		return (0);													//verifica um mapa valido
	//ft_print_struct(&game);										//print dados
	ft_game_start(&game);											// comeca o game
	ft_free_map(game.map);											//free map
	return (0);
}
