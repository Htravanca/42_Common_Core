
//fprintf(stderr, "path2:%s\n", path);
//fprintf(stderr, "path1:%s\n", path);


/* char	*ft_path(char **cmdsarr, char **envp)
{
	char	**options;
	char	*pfinal;
	int		i;

	i = 0;
	pfinal = NULL;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	options = ft_split(envp[i] + 5, ':');
	if (!options)
		return (NULL);
	pfinal = ft_find_path(options, cmdsarr[0]);
	ft_free_arr(options);
	return (pfinal);
} */


/* char	*ft_path(char **cmdsarr, char **envp)
{
	char	**options;
	char	*pfinal;
	int		i;

	i = 0;
	pfinal = NULL;
	if (!*envp)
		options = ft_options();
	else
	{
		while (!ft_strnstr(envp[i], "PATH", 4))
			i++;
		options = ft_split(envp[i] + 5, ':');
		if (!options)
			return (NULL);
	}
	pfinal = ft_find_path(options, cmdsarr[0]);
	ft_free_arr(options);
	return (pfinal);
} */


/* static void	ft_wait(int *pid, int i)
{
	int	j;
	int	status;

	j = 0;
	while (j <= i)
	{
		//fprintf(stderr, "j:%d\n", j);
		if (waitpid(pid[j], &status, 0) < 0)
		{
			perror("Error waiting for child process");
			exit(1);
		}
		if (WEXITSTATUS(status) != 0)
			exit(WEXITSTATUS(status));
		j++;
	}
} */

/* static void	ft_wait(void)
{
	int	status;

	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
} */

	/* waitpid(-1, &status, 0);
	fprintf(stderr, "error:%d\n", WEXITSTATUS(status));
	if (WEXITSTATUS(status) != 0)
	{
		waitpid(-1, NULL, 0);
		exit(WEXITSTATUS(status));
	}  */


/* static void	ft_loop_process(int argc, char **argv, char **envp)
{
	int	pid[10000];
	int	i;
	int	wfd;

	i = 2;
	while (i < (argc - 2))
	{
		pid[i - 2] = ft_execute_child(argv[i], envp);
		i++;
	}
	wfd = ft_handle_error(open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
				0644), "Error opening file2");
	dup2(wfd, STDOUT_FILENO);
	close(wfd);
	pid[i - 2] = ft_handle_error(fork(), "Fork error");
	if (pid[i - 2] == 0)
		ft_execute(argv[argc - 2], envp);
	ft_wait(i);
} */

/* int	ft_execute_child(char *argv, char **envp)
{
	int	fd[2];
	int	pid;

	ft_handle_error(pipe(fd), "Pipe Error");
	pid = ft_handle_error(fork(), "Fork error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		//dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		//close(fd[0]);
		ft_execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		//dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		//close(fd[1]);
	}
	return (pid);
} */

/* static void	ft_wait(int i)
{
	int	status;
	int	statusf;

	statusf = 0;
	while ((i - 2) >= 0)
	{
		waitpid(-1, &status, 0);
		fprintf(stderr, "path2:%d\n", WEXITSTATUS(status));
		if (WEXITSTATUS(status) != 0)
			statusf = WEXITSTATUS(status);
		i--;
	}
	exit(statusf);
} */

/* static void	ft_wait(int *pid, int i)
{
	int	j;
	int	status;

	j = 0;
	while (j <= i)
	{
		fprintf(stderr, "j:%d\n", j);
		if (waitpid(pid[j], &status, 0) < 0)
		{
			perror("Error waiting for child process");
			exit(1);
		}
		if (WEXITSTATUS(status) != 0)
			exit(WEXITSTATUS(status));
		j++;
	}
} */