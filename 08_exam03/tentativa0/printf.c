#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int ft_print_char(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_print_string(char *string)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if (!string)
    {
        count += ft_print_string("(null)");
        return (count);
    }
    while (string[i])
    {
        count += ft_print_char(string[i]);
        i++;
    }
    return (count);
}

void ft_print_nb(long nb, int max, char *base)
{
    if (nb >= max)
    {
		ft_print_nb((nb / max), max, base);
		ft_print_nb((nb % max), max, base);
	}
	else
		ft_print_char(base[nb]);
    
}

int ft_print_dec(int nb)
{
    int count;
    long new;

    count = 0;
    if (nb < 0)
    {
        count += ft_print_char('-');
        new = -(long)nb;
    }
    else
        new = nb;
    ft_print_nb(new , 10, "0123456789");
    while (new != 0)
    {
        new = new / 10;
        count++;   
    }
    return (count);
}

void ft_print_nb2(unsigned int nb, unsigned long max, char *base)
{
    if (nb >= max)
    {
		ft_print_nb((nb / max), max, base);
		ft_print_nb((nb % max), max, base);
	}
	else
		ft_print_char(base[nb]);
    
}

int ft_print_hex(unsigned int nb)
{
    int count;

    count = 0;
    ft_print_nb2(nb , 16, "0123456789abcdef");
    while (nb != 0)
    {
        nb = nb / 16;
        count++;   
    }
    return (count);
}

int ft_printf(const char *format, ... )
{
    va_list ap;
    int count;
    int i;

    i = 0;
    count = 0;
    va_start(ap, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if(format[i] == 's')
                count += ft_print_string(va_arg(ap, char *));
            if(format[i] == 'd')
                count += ft_print_dec(va_arg(ap, int));
            if(format[i] == 'x')
                count += ft_print_hex(va_arg(ap, unsigned int));
            if(format[i] == '%')
                count += ft_print_char('%');
        }
        else
            count += ft_print_char(format[i]);
        i++;
    }
    va_end(ap);
    return (count);
}

/* int main()
{
    char *string = "teste12";
    int total;

    printf("FT_PRINTF:\n");
    total = ft_printf("Isto e uma string:%s\n", string);
    printf("total:%d\n", total);
    total = ft_printf("Magic %s is %d\n", "number", 42);
    printf("total:%d\n", total);
    total = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    printf("total:%d\n\n\n", total);

    printf("PRINTF:\n");
    total = printf("Isto e uma string:%s\n", string);
    printf("total:%d\n", total);
    total = printf("Magic %s is %d\n", "number", 42);
    printf("total:%d\n", total);
    total = printf("Hexadecimal for %d is %x\n", 42, 42);
    printf("total:%d\n\n\n", total);
} */


static void	ft_string_tests(void)
{
	int	return_ft_printf;
	int	return_printf;

	printf("Test 1: Simple string\n");
	return_ft_printf = ft_printf("Hello, World!\n");
	return_printf = printf("Hello, World!\n");
	printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
	printf("Test 2: String with %%s specifier\n");
	return_ft_printf = ft_printf("This is a %s.\n", "string");
	return_printf = printf("This is a %s.\n", "string");
	printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
}

static void	ft_numeric_tests(void)
{
	int	return_ft_printf;
	int	return_printf;

	printf("Test 3: Integer with %%d specifier\n");
	return_ft_printf = ft_printf("The answer is %d.\n", 42);
	return_printf = printf("The answer is %d.\n", 42);
	printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
	printf("Test 4: Hexadecimal with %%x specifier\n");
	return_ft_printf = ft_printf("The value is %x.\n", 255);
	return_printf = printf("The value is %x.\n", 255);
	printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
	printf("Test 5: Multiple specifiers\n");
	return_ft_printf = ft_printf("String: %s, Integer: %d, Hex: %x\n", \
			"test", 123, 0xabc);
	return_printf = printf("String: %s, Integer: %d, Hex: %x\n", \
			"test", 123, 0xabc);
	printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
}

static void	ft_special_cases(void)
{
	int		return_ft_printf = 0;
	int		return_printf;
	char	*null_string;

	null_string = NULL;
	printf("Test 6: Null string\n");
	return_ft_printf = ft_printf("Null string: %s\n", null_string);
	return_printf = printf("Null string: %s\n", null_string);
	printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
	printf("Test 7: Percent sign\n");
	return_ft_printf = ft_printf("Print a percent sign: %%\n");
	return_printf = printf("Print a percent sign: %%\n");
	printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
}

static void	ft_edge_case_tests(void)
{
	int	return_ft_printf;
	int	return_printf;

	printf("Test 8: Maximum and minimum integers\n");
	return_ft_printf = ft_printf("INT_MAX: %d, INT_MIN: %d\n", \
			INT_MAX, INT_MIN);
	return_printf = printf("INT_MAX: %d, INT_MIN: %d\n", \
			INT_MAX, INT_MIN);
	printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
	printf("Test 9: UINT_MAX with %%x\n");
	return_ft_printf = ft_printf("UINT_MAX in hex: %x\n", UINT_MAX);
	return_printf = printf("UINT_MAX in hex: %x\n", UINT_MAX);
	printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
}

static void	ft_check_ft_printf(void)
{
	ft_printf("Testing ft_printf Started.\n");
	ft_string_tests();
	ft_numeric_tests();
	ft_special_cases();
	ft_edge_case_tests();
	ft_printf("Testing ft_printf complete.\n");
}

int	main()
{
	ft_check_ft_printf();
	return (0);
}
