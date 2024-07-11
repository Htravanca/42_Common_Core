#include "push_swap.h"

void ft_total_cost_calc(t_stack_node **lst)
{
    t_stack_node *temp;

    temp = *lst;
    while (temp)
    {
        temp->cost->total_cost =  temp->cost->ra +  temp->cost->rb + temp->cost->rr 
                                +  temp->cost->rra + temp->cost->rrb + temp->cost->rrr;
        temp = temp->next;
    }
}

void ft_best_cost(t_stack_node **lst)
{
    t_stack_node *temp;

    temp = *lst;
    while (temp)
    {
        while (temp->cost->ra >= 1 && temp->cost->rb >=1)
        {
            temp->cost->ra--;
            temp->cost->rb--;
            temp->cost->rr++;
        }
        while (temp->cost->rra >= 1 && temp->cost->rrb >=1)
        {
            temp->cost->rra--;
            temp->cost->rrb--;
            temp->cost->rrr++;
        }
        temp = temp->next;
    }
    ft_total_cost_calc(lst);
}

void ft_cost_calc_auxb(t_stack_node **b, t_stack_node *temp_b)
{
    int aux_up;
    int aux_dw;

    aux_up = temp_b->index - 1;
    aux_dw = ft_lst_size(*b) - temp_b->index + 1;
    if (aux_up <= aux_dw)
         temp_b->cost->rb = aux_up;
    else
        temp_b->cost->rrb = aux_dw;
}

void ft_cost_calc_auxa(t_stack_node **a, t_stack_node *temp_a, t_stack_node *temp_b)
{
    int aux_up;
    int aux_dw;

    aux_up = temp_a->index - 1;
    aux_dw = ft_lst_size(*a) - temp_a->index + 1;
    if (aux_up <= aux_dw)
        temp_b->cost->ra = aux_up;
    else
        temp_b->cost->rra = aux_dw;
}

void ft_cost_calc(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *temp_b;
    t_stack_node *temp_a;

    temp_b = *b;
    temp_a = *a;
    while (temp_b)
    {
        temp_a = *a;
        if(temp_b->index != 1)
            ft_cost_calc_auxb(b, temp_b);
        while (temp_a && temp_b->bf != temp_a->data)
            temp_a = temp_a->next;
        if(temp_a->index != 1)
            ft_cost_calc_auxa(a, temp_a, temp_b);
        temp_b = temp_b->next;
    }
    ft_best_cost(b);
}

void    ft_cost_clean(t_stack_node **b)
{
    t_stack_node *temp_b;

    temp_b = *b;
    while (temp_b)
    {
        temp_b->bf = 0;
        temp_b->cost->ra = 0;
        temp_b->cost->rb = 0;
        temp_b->cost->rr = 0;
        temp_b->cost->rra = 0;
        temp_b->cost->rrb = 0;
        temp_b->cost->rrr = 0;
        temp_b->cost->total_cost = 0;
        temp_b = temp_b->next;
    }
}
