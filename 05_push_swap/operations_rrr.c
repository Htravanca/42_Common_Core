#include "push_swap.h"

void rra(t_stack_node **a, int print)
{
    t_stack_node *temp;
    t_stack_node *temp_bg;
    t_stack_node *temp_lst;
    int index;

    index = 2;
    if (!(*a) || !((*a)->next))
        return ;
    temp_bg = (*a);
    temp = (*a);
    while (temp->next)
    {
        temp->index = index;
        temp_lst = temp;
        temp = temp->next;
        index++;
    }
    (*a) = temp;
    temp->next = temp_bg;
    temp->index = 1;
    temp_lst->next = NULL;
    if (print)
        printf("rra\n");
}

void rrb(t_stack_node **b, int print)
{
    t_stack_node *temp;
    t_stack_node *temp_bg;
    t_stack_node *temp_lst;
    int index;

    index = 2;
    if (!(*b) || !((*b)->next))
        return ;
    temp_bg = (*b);
    temp = (*b);
    while (temp->next)
    {
        temp->index = index;
        temp_lst = temp;
        temp = temp->next;
        index++;
    }
    (*b) = temp;
    temp->next = temp_bg;
    temp->index = 1;
    temp_lst->next = NULL;
    if (print)
        printf("rrb\n");
}
