#include "so_long.h"

int main(int argc, char **argv)
{
	
	if (ft_map_parsing(argc, argv))
		return (0);
	printf("name looks good\n\n");

	if(ft_check_map(argv[1]))
		return (0);
}
