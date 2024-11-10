#include <unistd.h>
#include <stdio.h>

#define BUFFER_PWD 4096

//ENV Builtins
int ft_env(char **env)
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

int main (int argc, char **argv, char **env)
{
    //ft_env(env);
    ft_pwd();
}