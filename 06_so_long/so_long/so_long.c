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

int main(int argc, char **argv)
{
	char **map;

	map = NULL;
	if (ft_map_parsing(argc, argv)) //confirma que o ficheiro existe e da para abrir e é um .ber
		return (0);
	map = ft_check_map(argv[1]);	//abre o ficheiro e cria com malloc um array 2D com o mapa 
	if(map == NULL)
		return (0);

	ft_print_map(map);				//print o mapa

	ft_map_checker(map);			//verifica um mapa valido
}
