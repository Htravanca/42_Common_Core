
// CD BUILTINS
int	ft_cd(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
		printf("Expected argument to \"cd\"\n");
	else if (i == 2)
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (-1);
		}
		return (0);
	}
	else
		printf("cd: too many arguments\n");
	return (-1);
}

// PWD BUILTINS
#define BUFFER_PWD 4096

int	ft_pwd(char **args)
{
	char	buffer[BUFFER_PWD];

	(void)args; // Ignore args since it's not used take this out
	if (getcwd(buffer, BUFFER_PWD) != NULL)
	{
		printf("%s\n", buffer);
		return (0);
	}
	else
	{
		perror("pwd");
		return (-1);
	}
}
