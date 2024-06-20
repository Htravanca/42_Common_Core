#include "list.h"

int ascending(int a, int b)
{
	return (a <= b);
}

void ft_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *temp = lst;
    int done = 1;

    while(done)
    {
        done = 0;
        while(temp->next)
        {
            if (cmp(temp->data,temp->next->data) == 0)
            {
                ft_swap(&temp->data, &temp->next->data);
                done = 1;
            }
            temp = temp->next;
        }
        temp = lst;
    }
    return (lst);
}

#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    t_list *a;
    t_list *b;
    t_list *c;
    t_list *d;
    t_list *e;


    a = malloc(sizeof(t_list));
    b = malloc(sizeof(t_list));
    c = malloc(sizeof(t_list));
    d = malloc(sizeof(t_list));
    e = malloc(sizeof(t_list));

    a->data = 18888888;
    a->next = b;

    b->data = 999;
    b->next = c;

    c->data = 99;
    c->next = d;

    d->data = 9;
    d->next = e;

    e->data = 1;
    e->next = 0;
    printf("a:%d\n",a->data);
    printf("b:%d\n",b->data);
    printf("c:%d\n",c->data);
    printf("d:%d\n",d->data);
    printf("e:%d\n",e->data);

    a = sort_list(a, ascending);
    printf("////////////////////////\n");

    printf("a:%d\n",a->data);
    printf("b:%d\n",b->data);
    printf("c:%d\n",c->data);
    printf("d:%d\n",d->data);
    printf("e:%d\n",e->data);

    
}