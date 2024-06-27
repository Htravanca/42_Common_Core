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

int ft_lsta_nok(t_stack_node *a)
{
    t_stack_node *temp;
    t_stack_node *temp_aux;

    temp = a;
    temp_aux = temp->next;
    while (temp)
    {
        temp_aux = temp->next;
        while (temp_aux)
        {
            if (temp->data == temp_aux->data)
                return (1);
            temp_aux = temp_aux->next;
        }
        temp = temp->next;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;
    
    a = NULL;
    b = NULL;
    if (argc == 1)
        return (0);
    if (argc == 2)
        a = ft_str_format(argv[1], a);
    if (argc >= 3)
        a = ft_argvs_format(argc, argv, a);

    //validar que a ista A nao tem repetidos
    if (ft_lsta_nok(a))
        ft_error_msg();

    //testes:
    b = ft_argvs_format(argc, argv, b);
    ft_printf_lst(a, 'a');
    ft_printf_lst(b, 'b');

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
}
