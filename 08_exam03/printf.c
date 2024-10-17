#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

void ft_putstr(char *str, int *length)
{
    if (str == NULL)
        str = "(null)";
    while(*str)
    {
        *length += write(1, str++, 1);
    }
}

void ft_putnbr(long long int nbr, int base, int *length)
{
    char *radix;

    radix = "0123456789abcdef";
    if (nbr < 0)
    {
        nbr = -nbr;
        *length += write(1, "-", 1);
    }
    if (nbr >= base)
        ft_putnbr(nbr / base, base, length);
    *length += write(1, &radix[nbr % base], 1);
}

int ft_printf(const char *format, ... )
{
    va_list args;
    int length;

    length = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'x' || *(format + 1) == 'd'))
        {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(args, char *), &length);
            if (*format == 'd')
                ft_putnbr((long long int)va_arg(args, int), 10, &length);
            if (*format == 'x')
                ft_putnbr((long long int)va_arg(args, unsigned int), 16, &length);
        }
        else
            length += write(1, format, 1);
        format++;
    }
    return (va_end(args), length);
}

// int main(void)
// {
//     ft_printf("%d\n", INT_MAX + 1);
//    