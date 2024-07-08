#include "push_swap.h"

void rra(t_stack_node **a, int print)
{
    t_stack_node *temp;
    t_stack_node *temp_bg;
    t_stack_node *temp_lst;

    if (!(*a) || !((*a)->next))
        return ;
    temp_bg = (*a);
    temp = (*a);
    while (temp->next)
    {
        temp_lst = temp;
        temp = temp->next;
    }
    (*a) = temp;
    temp->next = temp_bg;
    temp_lst->next = NULL;
    ft_update_index(a);
    if (print)
        write(1, "rra\n", 4);
}

void rrb(t_stack_node **b, int print)
{
    t_stack_node *temp;
    t_stack_node *temp_bg;
    t_stack_node *temp_lst;

    if (!(*b) || !((*b)->next))
        return ;
    temp_bg = (*b);
    temp = (*b);
    while (temp->next)
    {
        temp_lst = temp;
        temp = temp->next;
    }
    (*b) = temp;
    temp->next = temp_bg;
    temp_lst->next = NULL;
    ft_update_index(b);
    if (print)
        write(1, "rrb\n", 4);
}

void rrr(t_stack_node **a, t_stack_node **b)
{
    if (!(*b) || !((*b)->next) || !(*a) || !((*a)->next))
        return ;
    rra(a ,0);
    rrb(b ,0);
    write(1, "rrr\n", 4);
}
