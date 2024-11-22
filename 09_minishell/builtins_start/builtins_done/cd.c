#include "../minishell.h"
#define BUFFER_PWD 4096

// CD BUILTINS
// Expected input args[0]=cd; args[1]=Relative or absolute path; args[2]=NULL
// Return 0 Ok; -1 Error
char	*ft_get_cwd(void)
{
	char	buffer[BUFFER_PWD];
	char *pwd;

	if (getcwd(buffer, BUFFER_PWD) != NULL)
	{
		pwd = ft_strdup(buffer);
		if (!pwd)
			return (NULL);
		return (pwd);
	}
	else
	{
		perror("pwd");
		return (NULL);
	}
}

void	ft_change_pwd(envc *env)
{
	envc	*temp;
	char	*old;

	temp = env;
	old = NULL;
	while (temp)
	{
		if (ft_strncmp(temp->var, "OLDPWD", ft_strlen(temp->var)) == 0)
			if (temp->value)
					free(temp->value);
		if (ft_strncmp(temp->var, "PWD", ft_strlen(temp->var)) == 0)
			old = temp->value;
		temp = temp->next;
	}
	temp = env;
	while (temp)
	{
		if (ft_strncmp(temp->var, "OLDPWD", ft_strlen(temp->var)) == 0)
			temp->value = old;
		if (ft_strncmp(temp->var, "PWD", ft_strlen(temp->var)) == 0)
			temp->value = ft_get_cwd();
		temp = temp->next;
	}
}

int	ft_cd(char **args, envc *env)
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
		ft_change_pwd(env);
		return (0);
	}
	else
		printf("cd: too many arguments\n");
	return (-1);
}
