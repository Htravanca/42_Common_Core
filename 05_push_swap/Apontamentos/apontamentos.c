/* void ft_printf_lst(t_stack_node *a, char l)
{
    t_stack_node *temp;

    temp = a;
    if (!a)
    {
        printf("NULL\n");
        return ;
    }  
    while (temp)
    {
        if(temp->index <= 9)
            printf("%c%02d:%d\t\tbf:%d\t\tcost:%d\tra:%d\trb:%d\trr:%d\trra:%d\trrb:%d\trrr:%d\t\n", l, temp->index, temp->data, temp->bf, temp->cost->total_cost, 
            temp->cost->ra, temp->cost->rb, temp->cost->rr, temp->cost->rra, temp->cost->rrb, temp->cost->rrr);
        else
            printf("%c%d:%d\t\tbf:%d\t\tcost:%d\tra:%d\trb:%d\trr:%d\trra:%d\trrb:%d\trrr:%d\t\n", l, temp->index, temp->data, temp->bf, temp->cost->total_cost, 
            temp->cost->ra, temp->cost->rb, temp->cost->rr, temp->cost->rra, temp->cost->rrb, temp->cost->rrr);
        temp = temp->next;
    }
    printf("\n");
} */


