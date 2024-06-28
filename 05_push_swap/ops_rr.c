#include "push_swap.h"

void ra(t_stack_node **a, int print)
{
    t_stack_node *temp;
    t_stack_node *temp_bg;

    if (!(*a) || !((*a)->next))
        return ;
    temp_bg = (*a);
    temp = (*a);
    *a = (*a)->next;
    while(temp->next)
        temp = temp->next;
    temp->next = temp_bg;
    temp_bg->next = NULL;
    ft_update_index(a);
    if (print)
        printf("ra\n");
}

void rb(t_stack_node **b, int print)
{
    t_stack_node *temp;
    t_stack_node *temp_bg;

    if (!(*b) || !((*b)->next))
        return ;
    temp_bg = (*b);
    temp = (*b);
    *b = (*b)->next;
    while(temp->next)
        temp = temp->next;
    temp->next = temp_bg;
    temp_bg->next = NULL;
    ft_update_index(b);
    if (print)
        printf("rb\n");
}

void rr(t_stack_node **a, t_stack_node **b)
{
    if (!(*b) || !((*b)->next) || !(*a) || !((*a)->next))
        return ;
    ra(a, 0);
    rb(b, 0);
    printf("rr\n");
}
