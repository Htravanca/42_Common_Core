#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int a1;
    int a2;
    long result;

    if(argc == 4)
    {
        a1 = atoi(argv[1]);
        a2 = atoi(argv[3]);

        if (argv[2][0] == '+')
            result = a1 + a2;
        if (argv[2][0] == '-')
            result = a1 - a2;
        if (argv[2][0] == '*')
            result = a1 * a2;
        if (argv[2][0] == '/')
            result = a1 / a2;
        printf ("%ld\n", result);
    }else
        write(1,"\n", 1);
}
