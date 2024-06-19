#include <unistd.h>

int main(int argc, char **argv)
{
    int j;
    int flag = 0;

    j = 0;
    if (argc == 2)
    {
        while (argv[1][j])
        {
            while (argv[1][j] && (argv[1][j] == ' ' || argv[1][j] == '\t'))
                j++;
            while (argv[1][j] && argv[1][j] != ' ' && argv[1][j] != '\t')
            {
                if (flag && (argv[1][j + 1]) != '\0')
                {
                    write (1, &"   ", 3);
                    flag = 0;
                }
                write (1, &argv[1][j], 1);
                j++;
            }
            flag = 1;
        }
    }
    write (1, &"\n", 1);
}