#include "../minishell.h"

#define BUFFER_PWD 4096

// PWD BUILTINS
// Expected input void
// Return 0 Ok; -1 Error
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

