#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"

void ft_execute_child1(int *fd, char **argv)
{
    int rfd;
    rfd = open(argv[1], O_RDONLY);
    if (rfd == -1)
    {
        perror("Error opening file1");
        exit(1);
    }
    dup2(rfd, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(rfd);
    close(fd[0]);
    close(fd[1]);  
    //execlp(argv[2], argv[2], NULL);
    execlp("grep", "grep", "a1", NULL);
    perror("Error executing the cmd1");
    exit(1);
}
        
void ft_execute_child2(int *fd, char **argv)
{
    int wfd;
    wfd = open(argv[4], O_WRONLY);
    if (wfd == -1)
    {
        perror("Error opening file2");
        exit(1);
    }
    dup2(wfd, STDOUT_FILENO);
    dup2(fd[0], STDIN_FILENO);
    close(wfd);
    close(fd[0]);
    close(fd[1]);
    //execlp(argv[3], argv[3], NULL);
    execlp("wc", "wc", "-l", NULL);
    perror("Error executing the cmd2");
    exit(1);
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
            ft_execute_child1(fd, argv);
        pid2 = fork();
        if (pid2 < 0)
            return (0);
        if(pid2 == 0)
            ft_execute_child2(fd, argv);
        close(fd[0]);
        close(fd[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
    } else
        perror("Error in ARGS, correct usage: ./pipex file1 cmd1 cmd2 file2\n");
    return (0);
}


