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

int ft_wall_map(char **map)
{
    int j;
    int len;
    int i;

    i = 0;
    j = 0;
    while (map[0][j])
    {
        if (map[0][j] != '1' && map[0][j + 1] != '\0')
            return (1);
        j++;
    }
    j = 1;
    len = ft_strlen_map(map[0]) - 1;
    while (map[j])
    {
        if (map[j][0] != '1' || map[j][len] != '1')
            return (1);
        j++;
    }
    j--;
    while (map[j][i])
        if (map[j][i++] != '1')
            return (1);
    return (0);
}

int ft_map_checker(char **map)
{
    if (ft_map_square(map))
    {
        printf("mapa nao e quadrado\n");
        return (1);
    }
    if (ft_wall_map(map))
    {
        printf("mapa nao esta fechado por paredes\n");
        return (1);
    }


    return (0);
}