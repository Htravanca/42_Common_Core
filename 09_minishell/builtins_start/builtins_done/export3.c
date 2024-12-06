#include "../minishell.h"

// Prints de VARS in alphabetical order.
// creates (dupliate) a new list
// orders it
// prints it
// free
// Function to duplicate the linked list
t_envc	*ft_duplicate_env_list(t_envc *head)
{
	t_envc	*new;
	t_envc	*new_head;
	t_envc	*temp;

	new_head = NULL;
	while (head)
	{
		new = (t_envc *)malloc(sizeof(t_envc));
		if (!new)
			return (NULL);
		new->var = ft_strdup(head->var);
		new->value = ft_strdup(head->value);
		new->visible = head->visible;
		new->next = NULL;
		if (!new_head)
			new_head = new;
		else
			temp->next = new;
		temp = new;
		head = head->next;
	}
	return (new_head);
}

// Helper function to swap two t_envc nodes
void	swap_nodes(t_envc *a, t_envc *b)
{
	char	*temp_var;
	char	*temp_value;
	int		temp_visible;

	temp_var = a->var;
	temp_value = a->value;
	temp_visible = a->visible;
	a->var = b->var;
	a->value = b->value;
	a->visible = b->visible;
	b->var = temp_var;
	b->value = temp_value;
	b->visible = temp_visible;
}

// Function to manually sort the list using selection sort
void	sort_env_list(t_envc *head)
{
	t_envc	*current;
	t_envc	*min_node;
	t_envc	*ptr;

	if (!head)
		return ;
	current = head;
	while (current)
	{
		min_node = current;
		ptr = current->next;
		while (ptr)
		{
			if (ft_strcmp(ptr->var, min_node->var) < 0)
				min_node = ptr;
			ptr = ptr->next;
		}
		if (min_node != current)
			// Swap the current node with the smallest node found
			swap_nodes(current, min_node);
		current = current->next;
	}
}

// Function to print the sorted environment variables
void	ft_print_env_sorted(t_envc *head)
{
	t_envc	*new;
	t_envc	*temp;

	new = ft_duplicate_env_list(head);
	sort_env_list(new);
	temp = new;
	while (temp)
	{
		if (temp->visible) // Only print visible variables
		{
			printf("declare -x %s", temp->var);
			if (temp->value)
				printf("=\"%s\"", temp->value);
			printf("\n");
		}
		temp = temp->next;
	}
	ft_lstclear_env(&new);
}
