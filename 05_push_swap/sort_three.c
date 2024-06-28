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
