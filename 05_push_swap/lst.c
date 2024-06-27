#include "push_swap.h"

t_stack_node    *ft_lstnew(int content, int index)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->data = content;
    new->index = index;
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
