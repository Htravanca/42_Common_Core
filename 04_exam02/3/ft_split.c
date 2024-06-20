#include <stdlib.h>
#include <stdio.h>

int ft_count(char *str)
{
    int count;
    int k;

    k = 0;
    count = 0;
    while (str[k])
    {
        while (str[k] && (str[k] == ' ' || str[k] == '\t' || str[k] == '\n'))
            k++;
        if(str[k] && str[k] != ' ' && str[k] != '\t' && str[k] != '\n')
            count++;
        while (str[k] && str[k] != ' ' && str[k] != '\t' && str[k] != '\n')
            k++;
    }
    return (count);
}

int ft_len(char *str, int *pos)
{
    int len;
    int k;

    k = *pos;
    len = 0;
    while (str[k] && (str[k] == ' ' || str[k] == '\t' || str[k] == '\n'))
        k++;
    while (str[k] && str[k] != ' ' && str[k] != '\t' && str[k] != '\n')
    {
        k++;
        len++;
    }
    *pos = k;
    return (len);
}

void ft_fill(char *str, char *arr, int len, int pos)
{
    int i;
    int j;

    j = 0;
    i = pos - len;
    while (j < len)
    {
        arr[j] = str[j + i];
        j++; 
    }
    arr[j] = '\0';
}

char    **ft_split(char *str)
{
    int words;
    char **arr;
    int k;
    int pos;
    int len;

    k = 0;
    pos = 0;
    words = ft_count(str);
    arr = malloc(sizeof(char *) * (words + 1));
    if (!arr)
       return (NULL);
    arr[words] = 0;
    while (k < words)
    {
        len = ft_len(str, &pos);
        arr[k] = malloc(sizeof(char) * (len + 1));
        if (!arr[k])
            return (NULL);
        ft_fill(str, arr[k], len, pos);
        k++;
    }
    return (arr);
}

int main(void)
{
    char *a = "         aa bb bb cccd      ";
    char **b = ft_split(a);
    int k;

    k = 0;
    while (b && b[k])
    {
        printf("b[%d]:%s\n",k, b[k]);
        k++;
    }

}