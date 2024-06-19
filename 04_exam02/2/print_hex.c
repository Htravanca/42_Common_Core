#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
    int result;
    int sign;
    int k;

    result = 0;
    sign = 1;
    k = 0;
    while (str[k] == ' ' || str[k] == '\t' || str[k] == '\n' || str[k] == '\f' || str[k] == '\r')
        k++;
    if (str[k] == '-'|| str[k] == '+')
    {
        if (str[k] == '-')
            sign = -1;
        k++;
    }
    while (str[k] && str[k] >= '0' && str[k] <= '9')
    {
        result = result * 10 + str[k] - '0';
        k++;
    }
    return (result * sign);
}

void ft_print_hex(int nb)
{
    char arr[] = "0123456789abcdef";

    if (nb < 0)
    {
        nb = -nb;
        write(1, &"-", 1);
    }
    if(nb > 15)
    {
        ft_print_hex(nb / 16);
        ft_print_hex(nb % 16);
    }
    else
        write(1, &arr[nb], 1);
}

int main(int argc, char **argv)
{
    int nb;

    nb = 0;
    if(argc == 2)
    {
        nb = ft_atoi(argv[1]);
        //printf("%d\n",nb);
        ft_print_hex(nb);
    }
    else
        write(1, &"\n", 1);
}