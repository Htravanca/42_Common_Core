
int	ft_atoi(const char *str)
{
    int nb;
    int k;
    int sign;

    sign = 1;
    k = 0;
    nb = 0;
    while (str[k] == ' ' || str[k] == '\t' || str[k] == '\n' || str[k] == '\r' || str[k] == '\f')
        k++;
    if(str[k] == '-' || str[k] == '+')
    {
        if (str[k] == '-')
            sign = -1;
        k++;
    }
    while (str[k] && str[k] >= '0' && str[k] <= '9')
    {
        nb = nb * 10 + (str[k] - '0');
        k++;
    }
    return (nb * sign);
}
#include <stdio.h>
int main(void)
{
    printf("%d\n",ft_atoi("   123"));

}