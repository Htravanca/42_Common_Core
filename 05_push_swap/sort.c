#include "push_swap.h"

int ft_lst_size(t_stack_node *a)
{
    t_stack_node *temp;
	int i;

	i = 0;
    temp = a;
    while (temp)
    {
        i++;
        temp = temp->next;
    }
    return (i);
}

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

void    ft_sort(t_stack_node **a, t_stack_node **b)
{
    printf("sort func has started\n");
    ft_first_step(a, b);
    ft_sort_five(a, b);
}