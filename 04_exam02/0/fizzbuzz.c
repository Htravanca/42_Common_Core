#include <unistd.h>

void ft_print_nb(long nb)
{
    char n;

    if(nb < 0)
    {
        nb = -nb;
        write(1, "-", 1);
    }
    if (nb > 9)
    {
        ft_print_nb(nb / 10);
        ft_print_nb(nb % 10);
    }else
    {
        n = nb + 48; 
        write(1, &n, 1);
    }
}



int main(void)
{
    int nb;

    nb = 1;
    while (nb <= 100)
    {
        if ((nb % 15) == 0)
        {
            write(1,"fizzbuzz\n", 9);
        }else if ((nb % 5) == 0)
        {
            write(1,"buzz\n", 5);
        }else if ((nb % 3) == 0)
        {
            write(1,"fizz\n", 5);
        }else
        {
            ft_print_nb(nb);
            write(1, "\n", 1);
        }
        nb++;
    }
    
}