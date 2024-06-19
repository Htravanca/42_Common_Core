#include <stdio.h>

int ft_valid(char a, int str_base)
{
    char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

    while (str_base >= 0)
    {
        if (digits[str_base] == a || digits2[str_base] == a)
            return (1);
        str_base--;
    }
    return (0);
}

int ft_value(char c)
{
    if (c >= '0' && c<= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int result;
    int sign = 1;
    int j;

    j = 0;
    result = 0;
    if (!str || str_base <= 1 || str_base>16)
        return (0);
    if (str[0] == '-')
    {
        sign = -1;
        j++;
    }
    
    while (str[j] && ft_valid(str[j], str_base))
    {
        result = result * str_base + ft_value(str[j]);
        j++;
    }
    return (result * sign);
}

#include <stdio.h>
int main ()
{
    printf("%d\n",ft_atoi_base("10" ,10));
    printf("%d\n",ft_atoi_base("1111" ,16));
    printf("%d\n",ft_atoi_base("10101" ,2));
    printf("%d\n",ft_atoi_base("abcd" ,16));
    printf("%d\n",ft_atoi_base("-abcd" ,16));
}