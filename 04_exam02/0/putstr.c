#include <unistd.h>

void	ft_putstr(char *str)
{
    int k;

    k = 0;
    while (str[k])
    {
        write(1 , &str[k], 1);
        k++;
    }
}

/* int main(void)
{
    ft_putstr("123456789");
} */