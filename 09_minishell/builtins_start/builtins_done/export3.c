#include "../minishell.h"

// Function to duplicate the linked list
envc *duplicate_env_list(envc *head)
{
    envc *new_head = NULL;
    envc *current = head;
    envc *new_node = NULL;
    envc *last = NULL;

    while (current)
    {
        // Allocate memory for a new node
        new_node = (envc *)malloc(sizeof(envc));
        if (!new_node)
            return NULL;  // Return NULL if memory allocation fails

        // Duplicate the values
        new_node->var = strdup(current->var);
        new_node->value = current->value ? strdup(current->value) : NULL;
        new_node->visible = current->visible;
        new_node->next = NULL;

        // If the new list is empty, initialize it with the first node
        if (!new_head)
        {
            new_head = new_node;
            last = new_head;
        }
        else
        {
            last->next = new_node;
            last = new_node;
        }

        current = current->next;
    }

    return new_head;
}

// Helper function to swap two envc nodes
void swap_nodes(envc *a, envc *b)
{
    char *temp_var = a->var;
    char *temp_value = a->value;
    int temp_visible = a->visible;

    a->var = b->var;
    a->value = b->value;
    a->visible = b->visible;

    b->var = temp_var;
    b->value = temp_value;
    b->visible = temp_visible;
}

// Function to manually sort the list using selection sort
void sort_env_list(envc *head)
{
    envc *current, *min_node;
    envc *ptr;

    if (!head)
        return;

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

        // Swap the current node with the smallest node found
        if (min_node != current)
            swap_nodes(current, min_node);

        current = current->next;
    }
}

// Function to print the sorted environment variables
void ft_print_env_sorted(envc *head)
{
    sort_env_list(head); // Sort the linked list

    envc *current = head;
    while (current)
    {
        if (current->visible) // Only print visible variables
        {
            printf("declare -x %s", current->var);
            if (current->value)
                printf("=\"%s\"", current->value);
            printf("\n");
        }
        current = current->next;
    }
}

void ft_print_env_sorted(envc *head)
{

}
