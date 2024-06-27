#include "push_swap.h"

void ra(t_stack_node **a, int print)
{
    t_stack_node *temp;
    t_stack_node *temp_bg;
    int index;

    index = 0;
    if (!(*a) || !((*a)->next))
        return ;
    temp_bg = (*a);
    temp = (*a);
    *a = (*a)->next;
    (*a)->index = 1;
    while(temp->next)
    {
        temp->index = index;
        temp = temp->next;
        index++;
    }
    temp->next = temp_bg;
    temp->index = index;
    index++;
    temp_bg->next = NULL;
    temp_bg->index = index;

    if (print)
        printf("ra\n");
}

void rb(t_stack_node **b, int print)
{
    t_stack_node *temp;
    t_stack_node *temp_bg;
    int index;

    index = 0;
    if (!(*b) || !((*b)->next))
        return ;
    temp_bg = (*b);
    temp = (*b);
    *b = (*b)->next;
    (*b)->index = 1;
    while(temp->next)
    {
        temp->index = index;
        temp = temp->next;
        index++;
    }
    temp->next = temp_bg;
    temp->index = index;
    index++;
    temp_bg->next = NULL;
    temp_bg->index = index;

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
