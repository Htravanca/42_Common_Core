#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int tam;
    char *dest;

    tam = 0;
    while (src[tam])
        tam++;
    dest = malloc(sizeof(char) * tam + 1);
    if (!dest)
        return (NULL);
    tam = 0;
    while(src[tam])
    {
        dest[tam] = src[tam];
        tam++;
    }
    dest[tam] = '\0';
    return (dest);
}