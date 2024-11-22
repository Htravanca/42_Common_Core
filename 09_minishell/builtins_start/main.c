#include "minishell.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}


int	main(int argc, char **argv, char **env)
{
	//char **envc;
	envc *env_new;

	env_new = NULL;
	(void)argc;
	(void)argv;
	//(void)env;
	env_new = ft_env_cpy(env, env_new);

	ft_env(env_new);
	printf("\n\n\n");

	char **split;
	split = ft_split("cd ..", ' ');
	printf("OLD:");
	ft_pwd();
	printf("\n");
	ft_cd(split, env_new);
	printf("NEW:");
	ft_pwd();
	printf("\n");
	printf("\n\n\n");


	ft_env(env_new);
	

	//ft_free_envc(envc);
	ft_lstclear_env(&env_new);
	ft_free_split(split);
}

/* cd ~
printf("\n\n");
	char **split;
	split = ft_split("export VA123__R=lala", ' ');
	//printf("aqui\n");
	//envc = ft_unset(split, envc); //por tar aqui a passa um NULL tenho leaks.
	//printf("aqui\n");
	ft_export(split, envc);
	
	//ft_env(envc);
	
	printf("\n\n");
	// ft_pwd();
	ft_free_envc(split); */