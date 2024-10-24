#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_put_str(char *str)
{
    int i;
    int count;

    count = 0;
    i = 0;
    if (str == NULL)
    {
        ft_put_str("(null)");
        return (6);
    }
    while (str[i])
    {
        count += ft_putchar(str[i]);
        i++;
    }
    return (count);
}

void ft_print_nb(long n, int base, char *basechar)
{
    if (n >= base)
    {
        ft_print_nb((n / base), base, basechar);
        ft_print_nb((n % base), base, basechar);
    }
    else
        ft_putchar(basechar[n]);
}

int ft_put_nb(int nb)
{
    long n;
    int count;

    count = 0;
    if(nb < 0)
    {
        n = -(long)nb;
        count += ft_putchar('-');
    }
    else
        n = (long)nb;
    ft_print_nb(n, 10, "0123456789");
    while (n != 0)
    {
        n = n / 10;
        count ++;
    }
    if (nb == 0)
        return (1);
    return (count);
}

int ft_put_hex(unsigned int nb)
{
    long n;
    int count;

    count = 0;
    n = (long)nb;
    ft_print_nb(n, 16, "0123456789abcdef");
    while (n != 0)
    {
        n = n / 16;
        count ++;
    }
    if (nb == 0)
        return (1);
    return (count);
}

int ft_printf(const char *str, ... )
{
    va_list ap;
    int i;
    int count;

    i = 0;
    count = 0;
    va_start(ap, str);
    while (str[i])
    {
        if(str[i] == '%')
        {
            i++;
            if(str[i] == 's')
                count += ft_put_str(va_arg(ap, char *));
            else if(str[i] == 'd')
                count += ft_put_nb(va_arg(ap, int));
            else if(str[i] == 'x')
                count += ft_put_hex(va_arg(ap, unsigned int));
            else if(str[i] == '%')
                count += ft_putchar('%');
        }
        else
            count += ft_putchar(str[i]);
        i++;
    }
    va_end(ap);
    return (count);
}


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
	return_ft_printf = ft_printf("The answer is %d.\n", 0);
	return_printf = printf("The answer is %d.\n", 0);
    printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
	printf("Test 3: Integer with %%d specifier\n");
	return_ft_printf = ft_printf("The answer is %d.\n", 42);
	return_printf = printf("The answer is %d.\n", 42);
	printf("Return values -> ft_printf: %d, printf: %d\n\n", \
			return_ft_printf, return_printf);
    printf("Test 4: Hexadecimal with %%x specifier\n");
	return_ft_printf = ft_printf("The value is %x.\n", 0);
	return_printf = printf("The value is %x.\n", 0);
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

