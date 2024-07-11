#include "push_swap.h"

void ft_clean_lst(t_stack_node **lst)
{
    t_stack_node *temp;
    t_stack_node *next;

    if (!lst || !*lst)
        return;

    temp = *lst;
    while (temp)
    {
        next = temp->next;
        if (temp->cost)
            free(temp->cost);
        free(temp);
        temp = next;
    }
    *lst = NULL;
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
        else if(nodes == 4)
            ft_sort_four(&a, &b);
        else if(nodes == 5)
            ft_sort_five(&a, &b);
        else if (nodes > 5)
            ft_sort(&a, &b);
    }
    ft_clean_lst(&a);
    ft_clean_lst(&b);
}
