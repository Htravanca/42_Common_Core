#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int k;

    k = 0;
    while (str[k])
        k++;
    return (k);
}

int main(int argc, char **argv)
{
    int ini;
    int fim;
    char *temp;

    if(argc == 2)
    {
        temp = argv[1];
        ini = ft_strlen(temp) - 1;
        fim = ini;
        while(ini > 0)
        {
            while (temp[ini] && temp[ini] != ' ')
                ini--;
            write(1, &temp[ini + 1], fim - ini);
            if (ini > 1)
                write(1, &" ", 1);
            ini--;
            fim = ini;
        }

    }
}