#include "push_swap.h"

int ft_mean_val(t_stack_node *a)
{
    long long sum;
    int size;
    int result;
    t_stack_node *temp;

    sum = 0;
    temp = a;
    while (temp)
    {
        sum += temp->data;
        temp = temp->next;
    }
    if (sum == 0)
        return (0);
    size = ft_lst_size(a);
    result = sum / size;
    return (result);
}

void ft_first_step(t_stack_node **a, t_stack_node **b)
{
    int mean_val;

    mean_val = 0;
    while (ft_lst_size(*a) > 5)
    {
        mean_val = ft_mean_val(*a);
        if((*a)->data <= mean_val)
            pb(a, b);
        else
            ra(a, 1);
    }
}

void    ft_bf_finder(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *temp_b;
    t_stack_node *temp_a;
    int bf_found;
    int aux_sub;
    int prev_sub;

    bf_found = INT_MAX;
    temp_a = *a;
    temp_b = *b;
    while(temp_b)
    {
        temp_a = *a;
        bf_found = INT_MAX;
        prev_sub = INT_MAX;
        while (temp_a)
        {
            aux_sub = temp_a->data - temp_b->data;
            if(aux_sub > 0 && aux_sub < prev_sub)
            {
                bf_found = temp_a->data;
                prev_sub = aux_sub;
            }
            temp_a = temp_a->next;
        }
        temp_b->bf = bf_found;
        temp_b = temp_b->next;
    }
}

void ft_find_and_exec(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *temp_b;
    int cost_sm;
    int index;

    index = 0;
    cost_sm = INT_MAX;
    temp_b = *b;
    while (temp_b)
    {
        if(temp_b->cost->total_cost < cost_sm)
        {
            cost_sm = temp_b->cost->total_cost;
            index = temp_b->index;
        }
        temp_b = temp_b->next;
    }
    //printf("INDEX a ser feito:%d\n", index);
    temp_b = *b;
    while (temp_b->index != index)
        temp_b = temp_b->next;
    
    while (temp_b->cost->rr)
    {
        rr(a, b);
        temp_b->cost->rr--;
    }
    while (temp_b->cost->rrr)
    {
        rrr(a, b);
        temp_b->cost->rrr--;
    }
    while (temp_b->cost->ra)
    {
        ra(a, 1);
        temp_b->cost->ra--;
    }
    while (temp_b->cost->rb)
    {
        rb(a, 1);
        temp_b->cost->rb--;
    }
    while (temp_b->cost->rra)
    {
        rra(a, 1);
        temp_b->cost->rra--;
    }
    while (temp_b->cost->rrb)
    {
        rrb(a, 1);
        temp_b->cost->rrb--;
    }
}

void    ft_sort(t_stack_node **a, t_stack_node **b)
{
    int aux_up;
    int aux_dw;
    int index_sm;

    aux_up = 0;
    aux_dw = 0;
    //printf("sort func has started\n");
    //calula a media e move para a lista B caso esteja abaixo da media ate ficarem 5 na lista A
    ft_first_step(a, b);
    //Agora com 5 elem na lista A. Organiza-se
    ft_sort_five(a, b);

    while (ft_lst_size(*b) > 0)
    {
        //Calcula os BF da lista B com a lista A
        ft_bf_finder(a, b);

        //calcula o custo de por BF no top de A e o nr atual no topo de B
        ft_cost_calc(a, b);

        //Com os custo calculadps encontra o menor e executa-o 
        ft_find_and_exec(a, b);

        //limpa o custo de toda a lista
        ft_cost_clean(b);

        //push para A
        pa(a, b);
    }
    while (ft_index_sm(*a) != 1)
    {
        aux_up = ft_index_sm(*a) - 1;
        aux_dw = ft_lst_size(*a) - ft_index_sm(*a) + 1;
        if(aux_up < aux_dw)
            ra(a, 1);
        else
            rra(a ,1);
    }
    
}
