#include "so_long.h"

int ft_check_map_name(char *name)
{
    int fd;
    int pos;

    pos = 0;
    fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening map\n");
		return (1);
	}
    while (name[pos] != '.')
        pos++;
    if (!(name[pos] == '.' && name[pos + 1] == 'b' && name[pos + 2] == 'e' && name[pos + 3] == 'r' && name[pos + 4] == '\0'))
    {
        close(fd);
        return (1);
    }
    close(fd);
	return (0);
}

int ft_map_parsing(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Choose a map\n");
        return (1);
    }
    else if(argc == 2 && ft_check_map_name(argv[1]))
        return (1);
    else if (argc >= 3)
    {
        printf("Choose only a map\n");
        return (1);
    }
    return (0);
}