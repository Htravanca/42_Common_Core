#include "../minishell.h"

// ECHO BUILTINS
// Expected input args[0]=echo; args[1]=-n (opcional); args[n]="something"; args[last]=NULL;
// Return 0 Ok; -1 Error
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
