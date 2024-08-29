#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"

void	ft_free(char **var)
{
	int	i;

	i = 0;
	if (!var || !*var)
		return ;
	while (var[i] != NULL)
	{
		free(var[i]);
		i++;
	}
	free(var);
}

char *ft_path(char *cmd, char **envp)
{
    char *path;
    char **options;
    char **cmds;
    char *pfinal;
    int i;

    i = 0;
    pfinal = NULL;
    while (!ft_strnstr(envp[i], "PATH", 4)) // procura nos sistem variables a variavel PATH
        i++;
    options = ft_split(envp[i] + 5, ':');   //separa os paths possvies onde pode existir o cmd
    if (!options)
        return (NULL);
    cmds = ft_split(cmd, ' ');              //necessaio para tirar o -l do "ls -l"
    if (!cmds)
        return (NULL);
    i = 0;
    while(options[i])
    {
        options[i] = ft_strjoin(options[i],"/");
        options[i] = ft_strjoin(options[i],cmds[0]);
        if (access(options[i],F_OK) == 0)
        {
            pfinal = ft_strdup(options[i]);
            break;
        }
        i++;
    }
    //printf("options[%d]after:%s\n", i, options[i]);
    //printf("pfinal:%s\n", pfinal);
    ft_free(cmds);
    ft_free(options);
    return (pfinal);
}


void ft_execute_child1(int *fd, char **argv, char **envp)
{
    int rfd;
    char *path;

    /* rfd = open(argv[1], O_RDONLY, 0777);
    if (rfd == -1)
    {
        perror("Error opening file1");
        exit(1);
    }
    dup2(rfd, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(rfd);
    close(fd[0]);
    close(fd[1]); */

    path = ft_path(argv[2], envp);
    printf("path:%s\n",path);
/*     if (!path)
    {
        perror("Command not found");
        exit(1);
    }

    execve(path, &argv[2], envp); 
    perror("Error executing the cmd1");*/
    exit(1);
}
        
void ft_execute_child2(int *fd, char **argv, char **envp)
{
    int wfd;
    char *path;

    wfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
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
    /* path = get_cmd_path(argv[3], envp);
    if (!path)
    {
        perror("Command not found");
        exit(1);
    } */
    execve(path, &argv[3], envp);
    perror("Error executing the cmd2");
    exit(1);
}

int main (int argc, char **argv, char **envp)
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
            ft_execute_child1(fd, argv, envp);
        /* pid2 = fork();
        if (pid2 < 0)
            return (0);
        if(pid2 == 0)
            ft_execute_child2(fd, argv, envp); */
        close(fd[0]);
        close(fd[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
    } else
        perror("Error in ARGS, correct usage: ./pipex file1 cmd1 cmd2 file2\n");
    return (0);
}


