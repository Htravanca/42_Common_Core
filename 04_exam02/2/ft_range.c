#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int a;
    int *arr;
    int k;

    k = 0;
    a = 0;
    if (start > end)
        a = start - end + 1;
    else
        a = end - start + 1;
    arr = (int *)malloc(a * sizeof(int));
    if (!arr)
        return (0);
    while (a)
    {
        arr[k] = start;
        a--;
        k++;
        if (start > end)
            start--;
        else
            start++;
    }
    return (arr);
}

int main ()
{
    int *j = ft_range(-1,2);
    int n = 4;
    int k = 0;

    while(n)
    {
        printf("j[%d]=%d\n", k, j[k]);
        k++;
        n--;
    }

}