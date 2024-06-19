void	ft_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

/* #include <stdio.h>

int main()
{
    int a;
    int b;

    a = 10;
    b = 5;
    printf("a:%d, b:%d\n", a,b);
    ft_swap(&a, &b);
    printf("a:%d, b:%d", a,b);
} */