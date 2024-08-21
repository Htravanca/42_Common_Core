#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft/libft.h"

void ft_execute_child(int *fd, char **argv)
{
    //Child process
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);  
    execlp(argv[4], argv[3], NULL);
}
        
void ft_execute_parent(int *fd, char **argv)
{
    //Child process
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    close(fd[1]);
    execlp(argv[1], argv[2], NULL);
}

int main (int argc, char **argv)
{
    int fd[2];
    int pid1;
    int pid2;

    if (argc == 5)
    {
        if (pipe(fd) == -1)
            return (0);
        pid1 = fork();
        if (pid1 < 0)
            return (0);
        if(pid1 == 0)
            ft_execute_child(fd, argv);
        pid2 = fork();
        if (pid2 < 0)
            return (0);
        if(pid2 == 0)
            ft_execute_parent(fd, argv);
        close(fd[0]);
        close(fd[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
    } else
        perror("Error in ARGS, correct usage: ./pipex file1 cmd1 cmd2 file2\n");
    return (0);
}


