#include "pipex.h"

void	ft_execute_child1(int *fd, char **argv, char **envp)
{
	int		rfd;
	char	*path;
	char	**cmdsarr;

	rfd = open(argv[1], O_RDONLY, 0777);
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
	path = ft_path(argv[2], envp);
	//fprintf(stderr, "path1:%s\n", path);
	if (!path)
	{
		perror("Command not found");
		exit(1);
	}
	cmdsarr = ft_split(argv[2], ' ');
	if (!cmdsarr)
	{
		perror("Error while spliting the comands");
		exit(1);
	}
	execve(path, cmdsarr, envp);
	perror("Error executing the cmd1");
	ft_free(cmdsarr); // dont forget to free this
	free(path);       // dont forget to free this
	exit(1);
}

void	ft_execute_child2(int *fd, char **argv, char **envp)
{
	int		wfd;
	char	*path;
	char	**cmdsarr;

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
	path = ft_path(argv[3], envp);
	//fprintf(stderr, "path2:%s\n", path);
	if (!path)
	{
		perror("Command not found");
		exit(1);
	}
	cmdsarr = ft_split(argv[3], ' ');
	if (!cmdsarr)
	{
		perror("Error while spliting the comands");
		exit(1);
	}
	execve(path, cmdsarr, envp);
	perror("Error executing the cmd2");
	ft_free(cmdsarr); // dont forget to free this
	free(path);       // dont forget to free this
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (0);
		pid1 = fork();
		if (pid1 < 0)
			return (0);
		if (pid1 == 0)
			ft_execute_child1(fd, argv, envp);
		pid2 = fork();
		if (pid2 < 0)
			return (0);
		if (pid2 == 0)
			ft_execute_child2(fd, argv, envp);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		perror("Error in ARGS, correct usage: ./pipex file1 cmd1 cmd2 file2\n");
	return (0);
}