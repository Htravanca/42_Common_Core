#include "../minishell.h"

// CD BUILTINS
// Expected input args[0]=cd; args[1]=Relative or absolute path; args[2]=NULL
// Return 0 Ok; -1 Error
// Falta atualizar os ENV com o novo PWD e o OLD_PWD <--------------------------------------------

void    ft_change_pwd(envc *env)
{
    envc *temp;

    temp = env;
    while (temp && ft_strncmp(temp->var, "OLDPWD", ft_strlen(temp->var)) != 0)
    {
        printf("%s\n", temp->var);
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
