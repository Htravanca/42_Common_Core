
/* void ft_argvs_format(int argc, char **argv)
{
    int i;
    long nb;

    i = 1;
    //ver se os argumentos de entrada sao so numeros e sinais
    while (i < argc)
    {
        if (ft_nb_str_valid(argv[i]))
            i++;
        else
        {
            printf("Error\n");
            exit(0);
        }
    }
    //ja vi que os numeros sao validos
    //agora uso o atoi para tirar os numeros e escreve dentro da lista
    i = 1;
    while (i < argc)
    {
        nb = ft_atoi(argv[i]);
        if (ft_nb_limit(nb))
            printf("%ld\n",nb);
        else
        {
            //ft_free
            printf("Error\n");
            exit(0);
        }
        i++;
    } 

} */

/* int ft_nb_limit(long nb)
{
    if (nb >= INT_MIN && nb <= INT_MAX)
        return (1);
    return (0);
} */

/* void ft_str_format(char *str)
{
    char **a;
    int elem;
    int j;
    long nb;

    j = 0;
    elem = 0;
    a = ft_split(str, ' ');
    while (a[elem])
        elem++;
    while (j < elem)
    {
        if (ft_nb_str_valid(a[j]))
            j++;
        else
        {
            printf("Error\n");
            exit(0);
        }
    }
    //ja vi que os numeros sao validos
    //agora uso o atoi para tirar os numeros e escreve dentro da lista
    j = 0;
    while (j < elem)
    {
        nb = ft_atoi(a[j]);
        if (ft_nb_limit(nb))
            printf("%ld\n",nb);
        else
        {
            //ft_free
            printf("Error\n");
            exit(0);
        }
        j++;
    }

} */