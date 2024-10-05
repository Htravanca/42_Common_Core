
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