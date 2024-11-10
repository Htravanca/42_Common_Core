
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

int	ft_pwd(void)
{
	char	buffer[BUFFER_PWD];

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

// ECHO BUILTINS
int	ft_echo(char **args)
{
	int	newline;
	int	i;

	newline = 1;
	i = 1;
	if (args[i] && ft_strcmp(args[i], "-n") == 0)
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}

// ENV Builtins
int	ft_env(char **env)
{
	int i;

	i = 0;
	if (env == NULL)
		return (-1);
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}