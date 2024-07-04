#include "push_swap.h"

int ft_index_bg(t_stack_node *a)
{
    long nb;
    t_stack_node *temp;
    int index;

    nb = (long)INT_MIN - 1;
    temp = a;
    index = 0;
    while (temp)
    {
        if (nb < temp->data)
        {
            nb = temp->data;
            index = temp->index;
        }
        temp = temp->next;
    }
    return (index);
}

int ft_index_sm(t_stack_node *a)
{
    long nb;
    t_stack_node *temp;
    int index;

    nb = (long)INT_MAX + 1;
    temp = a;
    index = 0;
    while (temp)
    {
        if (nb > temp->data)
        {
            nb = temp->data;
            index = temp->index;
        }
        temp = temp->next;
    }
    return (index);
}

void    ft_sort_three(t_stack_node **a)
{
    int index_bg;
    int index_sm;

    index_bg = ft_index_bg(*a);
    index_sm = ft_index_sm(*a);
    if(index_bg == 2 && index_sm == 1)
    {
        rra(a, 1);
        sa(a, 1);
    }
    else if (index_bg == 2 && index_sm == 3)
        rra(a, 1);
    else if (index_bg == 3 && index_sm == 2)
        sa(a, 1);
    else if (index_bg == 1 && index_sm == 3)
    {
        ra(a, 1);
        sa(a, 1);
    }
    else if (index_bg == 1 && index_sm == 2)
        ra(a, 1);
}

void ft_put_top_a(t_stack_node **a, int index_sm, int size)
{
    if (index_sm == 1)
        return ;
    else if (index_sm == 2)
        sa(a, 1);
    else if (size == 4)
    {
        if (index_sm == 3)
            rra(a , 1);
        rra(a, 1);
    }
    else if (size == 5)
    {
        if (index_sm == 3)
        {  
            ra(a, 1);
            ra(a, 1);
            return ;
        }
        else if (index_sm == 4)
            rra(a , 1);
        rra(a, 1);
    }
}

void    ft_sort_four(t_stack_node **a, t_stack_node **b)
{
    int index_sm;

    index_sm = ft_index_sm(*a);
    ft_put_top_a(a, index_sm, 4);
    if (ft_is_lst_sorted(*a) == 0)
    {
        pb(a, b);
        ft_sort_three(a);
        pa(a, b);
    }
}

void    ft_sort_five(t_stack_node **a, t_stack_node **b)
{
    int index_sm;

    index_sm = ft_index_sm(*a);
    ft_put_top_a(a, index_sm, 5);
    if (ft_is_lst_sorted(*a) == 0)
    {
        pb(a, b);
        index_sm = ft_index_sm(*a);
        ft_put_top_a(a, index_sm, 4);
        if (ft_is_lst_sorted(*a) == 0)
        {
            pb(a, b);
            ft_sort_three(a);
            pa(a, b);
        }
        pa(a, b);
    }
}
