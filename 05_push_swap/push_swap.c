
#include "push_swap.h"

long ft_atoi(char *str)
{
    int i;
    long result;
    int sign;

    i = 0;
    result = 0;
    sign = 1;
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r')
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        if (-result <= INT_MIN || result >= INT_MAX)
            return ((long)INT_MAX +1);
        i++;
    }
    return (result * sign);
}

int ft_nb_str_valid(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (i == 0)
        {
            if(!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'))
                return (0);
        }
        else
        {
            if(!(str[i] >= '0' && str[i] <= '9'))
                return (0);
        }
        i++;
    } 
    return (1);
}

void ft_error_msg(void)
{
    printf("Error\n");
    exit(0);
}

void ft_str_format(char *str)
{
    char **a;
    int elem;
    int j;
    long nb;
    long error;

    error = (long)INT_MAX + 1;
    j = 0;
    elem = 0;
    a = ft_split(str, ' ');
    while (a[elem])
        elem++;
    while (j < elem)
    {
        if (ft_nb_str_valid(a[j]))
        {
            nb = ft_atoi(a[j]);
            //se o atoi devolver INT_MAX + 1 e pq o numero rebenta o tipo int
            if (nb == error)
            {
                ft_free(a,elem);
                ft_error_msg();
            }
            printf("%ld\n",nb);
            j++;
        }
        else
            ft_error_msg();
    }
} 

void ft_argvs_format(int argc, char **argv)
{
    int i;
    long nb;
    long error;

    error = (long)INT_MAX + 1;
    i = 1;
    while (i < argc)
    {   
        //ver se os argumentos de entrada sao so numeros e sinais
        if (ft_nb_str_valid(argv[i]))
        {
            nb = ft_atoi(argv[i]);
            //se o atoi devolver INT_MAX + 1 e pq o numero rebenta o tipo int
            if (nb == error)
            {
                //ft_free
                ft_error_msg();
            }
            printf("%ld\n",nb);
            i++;
        }
        else
            ft_error_msg();
    }
}

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;
    
    if (argc == 1)
        return (0);
    if (argc == 2)
        ft_str_format(argv[1]);
    if (argc >= 3)
        ft_argvs_format(argc, argv);
}
