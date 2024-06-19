#include <unistd.h>

int main(int argc, char **argv)
{
    int j;
    int k;

    j = 0;
    k = 0;
    if (argc == 3)
    {
        while (argv[1][j] && argv[2][k])
        {
            if (argv[1][j] == argv[2][k])
                j++;
        k++;
        }
        if(argv[1][j] == '\0')
            write(1, &"1", 1);
        else
            write(1, &"0", 1);
    }
    else
        write(1, &"\n", 1);
    return (0);
}