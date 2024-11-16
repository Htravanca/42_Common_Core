#include "minishell.h"

#define BUFFER_PWD 4096

// ENV Builtins
int	ft_env(char **env)
{
	int	i;

	i = 0;
	if (env == NULL)
		return (-1);
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "=", ft_strlen(env[i])))
			printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

void	ft_free_envc(char **envc)
{
	int	i;

	i = 0;
	if (envc == NULL)
		return ;
	while (envc[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(envc[i]);
		i--;
	}
	free(envc);
}

envc	*ft_lstnew(char *env)
{
	envc	*new;

	new = malloc(sizeof(envc));
	if (!new)
		return (NULL);
	new->var = ; //not done yet
	new->value = ;//not done yet
	new->visible = 1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(envc **env_new, char *env)
{
	envc	*temp;
	envc	*new;

	new = ft_lstnew(env);
	if (!new || !env_new)
		return ;
	if (!(*env_new))
	{
		*env_new = new;
		return ;
	}
	temp = *env_new;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

envc *ft_env_cpy(char **env, envc *env_new)
{
	int		i;

	i = 0;
	if (env == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		ft_lstadd_back(&env_new, env[i]);
		i++;
	}
	return (env_new);
}



int	main(int argc, char **argv, char **env)
{
	//char **envc;
	envc *env_new;

	env_new = NULL;
	(void)argc;
	(void)argv;
	env_new = ft_env_cpy(env, env_new);
	//ft_env(envc);

	//ft_free_envc(envc);
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