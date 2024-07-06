#include "push_swap.h"

t_stack_node    *ft_lstnew(int content, int index)
{
	t_stack_node	*new;
    t_cost          *cost;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
    cost = malloc(sizeof(t_cost));
    if (!cost)
		return (NULL);
	new->data = content;
    new->index = index;
    new->bf = 0;
    new->cost = cost;
    new->cost->ra = 0;
    new->cost->rb = 0;
    new->cost->rr = 0;
    new->cost->rra = 0;
    new->cost->rrb = 0;
    new->cost->rrr = 0;
    new->cost->total_cost = 0;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_stack_node **lst, int content, int index)
{
	t_stack_node	*temp;
    t_stack_node	*new;

    new = ft_lstnew(content, index);
	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int ft_lsta_nok(t_stack_node *a)
{
    t_stack_node *temp;
    t_stack_node *temp_aux;
	int i;

	i = 0;
    temp = a;
    temp_aux = temp->next;
    while (temp)
    {
        temp_aux = temp->next;
        while (temp_aux)
        {
            if (temp->data == temp_aux->data)
                return (0);
            temp_aux = temp_aux->next;
        }
		i++;
        temp = temp->next;
    }
    return (i);
}

int ft_is_lst_sorted(t_stack_node *a)
{
    long nb;
    t_stack_node *temp;

    nb = (long)INT_MIN - 1;
    temp = a;
    while (temp)
    {
        if (nb < temp->data)
        {
            nb = temp->data;
            temp = temp->next;
        }
        else
            return (0);
    }
    return (1);
}

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
