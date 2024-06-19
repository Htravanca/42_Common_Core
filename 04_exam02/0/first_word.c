#include <unistd.h>

int main(int argc, char **argv)
{
    int k;

    k = 0;
    if(argc == 2)
    {
        while (argv[1][k] && (argv[1][k] == 32 || argv[1][k] == 9))
            k++;
        while (argv[1][k] && argv[1][k] != 32 && argv[1][k] != 9)
        {
            write(1, &argv[1][k],1);
            k++;
        }
    }
    write(1, "\n",1);
    return (0);
}