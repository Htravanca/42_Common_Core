#include "push_swap.h"

void ft_printf_lst(t_stack_node *a, char l)
{
    t_stack_node *temp;

    temp = a;
    if (!a)
    {
        printf("NULL\n");
        return ;
    }  
    while (temp)
    {
        if(temp->index <= 9)
            printf("%c%02d:%d\n", l, temp->index, temp->data);
        else
            printf("%c%d:%d\n", l, temp->index, temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;
    int nodes;
    
    a = NULL;
    b = NULL;
    nodes = 0;
    if (argc == 1)
        return (0);
    if (argc == 2)
        a = ft_str_format(argv[1], a);
    if (argc >= 3)
        a = ft_argvs_format(argc, argv, a);
    //validar que a ista A nao tem repetidos e tambem devolve o nr de elementos
    nodes = ft_lsta_nok(a);
    if (nodes == 0)
        ft_error_msg();
    //ve se A esta sorted, se nao comeca a dar sort
    if(ft_is_lst_sorted(a) == 0)
    {
        if(nodes == 2)
            sa(&a, 1);
        else if(nodes == 3)
            ft_sort_three(&a);
    }
    else
        printf("sorted!\n");

    ft_printf_lst(a, 'a');
}
