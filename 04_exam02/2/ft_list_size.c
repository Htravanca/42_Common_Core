typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
    t_list *temp;
    int k;

    k = 1;
    temp = begin_list;
    while (temp->next)
    {
        temp = temp->next;
        k++;
    }
    return (k);
}
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    t_list *a;
    t_list *b;
    t_list *c;

    a = malloc(sizeof(t_list));
    b = malloc(sizeof(t_list));
    c = malloc(sizeof(t_list));

    a->data = (void*)10;
    a->next = b;

    b->data = (void*)2;
    b->next = c;
    
    c->data = (void*)99;
    c->next = 0;

    int j = ft_list_size(a);

    printf("%d\n",j);
}