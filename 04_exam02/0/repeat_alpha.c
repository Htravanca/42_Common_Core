#include<unistd.h>

int main(int argc, char **argv)
{
    int j;
    int nb;

    nb = 0;
    j = 0;
    if(argc == 2)
    {
        while (argv[1][j])
        {
            nb = 0;
            if (argv[1][j] >= 65 && argv[1][j] <= 90)
                nb = argv[1][j] - 65;
            if (argv[1][j] >= 97 && argv[1][j] <= 122)
                nb = argv[1][j] - 97;
            while (nb)
            {
                write(1, &argv[1][j],1);
                nb--;
            }
            if (!nb)
                write(1, &argv[1][j],1);
            j++;
        }
    }
    write(1,"\n",1);
    return (0);
}