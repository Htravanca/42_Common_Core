#include "so_long.h"

int ft_strlen_map(char *line)
{
    int j;
    int valid;

    j = 0;
    valid = 0;
    while (line[j])
    {
        if (line[j] == '0' || line[j] == '1' || line[j] == 'C' || line[j] == 'E' || line[j] == 'P')
            valid++;
        j++;
    }
    if(line[j - 1] == '\n')
        j--;
    if(j != valid)
       return (0);
    return (j);
}

int ft_map_square(char **map)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen_map(map[i]);
    i++;
    while (map[i] && ft_strlen_map(map[i]) == len)
        i++;
    if (map[i] != NULL)
        return (1);
    return (0);
}


int ft_map_checker(char **map)
{
    if (ft_map_square(map))
    {
        printf("mapa n e quadrado\n");
        return (1);
    }
        


    return (0);
}