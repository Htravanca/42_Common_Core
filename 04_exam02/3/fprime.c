#include <stdlib.h>
#include <stdio.h>

int ft_is_prime(int nb)
{
    int k;

    k = 2;
    while (k < nb)
    {
        if ((nb % k) == 0)
            return (0);
        k++;
    }
    return (1);
}

void ft_print_prime(int nb)
{
    int div;

    div = 2;
    while(nb > 1)
    {
        if ((nb % div) == 0 && ft_is_prime(div))
        {
            if (nb / div > 1)
                printf("%d*",div);
            else
                printf("%d",div);
            nb /= div;
        }
        else
            div++;
    }
}

int main(int argc, char **argv)
{
    int nb;

    nb = 0;
    if (argc == 2)
    {
        nb = atoi(argv[1]);
        if (ft_is_prime(nb))
            printf("%d\n",nb);
        else
            ft_print_prime(nb);
    }
    else
        printf("\n");
}