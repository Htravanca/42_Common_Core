#include "push_swap.h"

void sa(t_stack_node **a, int print)
{
    t_stack_node *temp;
    t_stack_node *temp_next;

    if (!(*a) || !((*a)->next))
        return ;
    temp = (*a);
    temp_next = (*a)->next->next;
    *a = (*a)->next;
    (*a)->next = temp;
    (*a)->next->next = temp_next;
    ft_update_index(a);
    if (print)
        printf("sa\n");
}

void sb(t_stack_node **b, int print)
{
    t_stack_node *temp;
    t_stack_node *temp_next;

    if (!(*b) || !((*b)->next))
        return ;
    temp = (*b);
    temp_next = (*b)->next->next;
    *b = (*b)->next;
    (*b)->next = temp;
    (*b)->next->next = temp_next;
    ft_update_index(b);
    if (print)
        printf("sb\n");
}

void ss(t_stack_node **a, t_stack_node **b)
{
    if (!(*b) || !((*b)->next) || !(*a) || !((*a)->next))
        return ;
    sa(a, 0);
    sb(b, 0);
    printf("ss\n");
}
