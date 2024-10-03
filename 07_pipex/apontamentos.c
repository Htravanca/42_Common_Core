
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