#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
    int result;
    int sign;
    int j;

    j = 0;
    result = 0;
    sign = 1;
    while(str[j] == ' ' || str[j] == '\t' || str[j] == '\n' || str[j] == '\f' || str[j] == '\r')
        j++;
    if(str[j] == '-' || str[j] == '+')
    {
        if (str[j] == '-' )
            sign = -1;
        j++;
    }
    while (str[j] && str[j] >= '0' && str[j] <= '9')
    {
        result = result * 10 + str[j] - '0';
        j++;
    }
    return (result * sign);
}

int ft_is_prime(int nb)
{
    int j;

    j = nb - 1;
    while (j != 1 && (nb % j) != 0 )
    {
        j--;
    }
    if (j == 1)
        return (1);
    return (0);
}

void ft_print_nb(int nb)
{
    char c;

    if (nb < 0)
    {
        nb = -nb;
        write (1, &"-", 1);
    }
    if (nb > 9)
    {
        ft_print_nb(nb / 10);
        ft_print_nb(nb % 10);
    } else
    {
        c = nb + '0';
        write (1, &c, 1);
    }
}

int main(int argc, char **argv)
{
    int nb;
    int result;

    result = 0;
    nb = 0;
    if (argc == 2)
    {
        nb = ft_atoi(argv[1]);
        if (nb >= 0)
        {
            while (nb != 1)
            {
                if (ft_is_prime(nb))
                    result += nb;
                nb--;
            }
            ft_print_nb(result);
        }
    }
    write(1, &"\n",1);
    return (0);
}