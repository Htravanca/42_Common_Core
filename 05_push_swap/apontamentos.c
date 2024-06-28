
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



   //TESTES DE SA SB SS
/*     sa(&a, 1);
    sb(&b, 1);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');
    ss(&a, &b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b'); */


    //TESTES DE RA RB RR
/*     ra(&a,1);
    rb(&b,1);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

    rr(&a, &b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

    rr(&a, &b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

    rr(&a, &b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

    rr(&a, &b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b'); */

    //TESTES DE RRA RRB RRR
/*     rra(&a, 1);
    ft_printf_lst(a, 'a');
    rrb(&b, 1);
    ft_printf_lst(b, 'b');

    rra(&a, 1);
    ft_printf_lst(a, 'a');
    rrb(&b, 1);
    ft_printf_lst(b, 'b');

    rra(&a, 1);
    ft_printf_lst(a, 'a');
    rrb(&b, 1);
    ft_printf_lst(b, 'b'); 
    rrr(&a, &b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b'); */

    //TESTE DE PA E PB
/*     pb(&a, &b);
    pb(&a, &b);
    pb(&a, &b);
    pa(&a, &b);
    pa(&a, &b);
    pa(&a, &b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b'); */
    


    //***************************************************************

    /*     //testes:
    //b = ft_argvs_format(argc, argv, b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

    //teste da folha enunciado
    sa(&a,1);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

    pb(&a, &b);
    pb(&a, &b);
    pb(&a, &b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

    ra(&a,1);
    rb(&b,1);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

    rra(&a, 1);
    rrb(&b, 1);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

    sa(&a,1);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

    pa(&a, &b);
    pa(&a, &b);
    pa(&a, &b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b'); */