#include "minishell.h"


int	main(int argc, char **argv, char **env)
{
	//char **envc;
	envc *env_new;

	env_new = NULL;
	(void)argc;
	(void)argv;
	env_new = ft_env_cpy(env, env_new);
	//print_env_list(env_new);
	ft_env(env_new);

	//ft_free_envc(envc);
	ft_lstclear_env(&env_new);
}

/* 
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