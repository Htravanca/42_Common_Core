#include <stdlib.h>
#include <stdio.h>

int ft_tam(int nb)
{
    int k;

    k = 0;
    while (nb != 0)
    {
        nb = nb / 10;
        k++;
    }
    return (k);    
}

char	*ft_itoa(int nbr)
{
    int t;
    char *s;
    long nb;

    nb = nbr;
    t = ft_tam(nb);
    if (nb < 0)
        t++;
    s = malloc(sizeof(char) * (t + 1));
    if (!s)
        return (NULL);
    s[t] = '\0';
    if (nb < 0)
    {
        s[0] = '-';
        nb = -nb;
    }
    t--;
    while (nb != 0)
    {
        s[t] = (nb % 10) + '0';
        t--;
        nb = nb / 10;
    }
    return (s);
}

int main(void)
{
    printf("%s\n",ft_itoa(2147483647));
}
