#include "minishell.h"

//RETURN a string with VAR
char *ft_env_var(char *env)
{
	int i;
	char *var;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	var = (char *)malloc(sizeof(char) * (i + 1));
	if (!var)
		return (NULL);
	i = 0;
	while (env[i] && env[i] != '=')
	{
		var[i] = env[i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

//RETURN a string with VAR
char *ft_env_value(char *env)
{
	int i;
	int j;
	char *var;

	i = 0;
	j = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++; //aaaaa
	while (env[j])
		j++;
	var = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!var)
		return (NULL);
	j = 0;
	while (env[i])
	{
		var[j] = env[i];
		i++;
		j++;
	}
	var[j] = '\0';
	return (var);
}

//Create a new node of list
envc	*ft_lstnew_env(char *env)
{
	envc	*new;

	new = malloc(sizeof(envc));
	if (!new)
		return (NULL);
	new->var = ft_env_var(env);
	new->value = ft_env_value(env);
	new->visible = 1;
	new->next = NULL;
	return (new);
}

//Add the new node to the back of the list
void	ft_lstadd_back_env(envc **env_new, char *env)
{
	envc	*temp;
	envc	*new;

	new = ft_lstnew_env(env);
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

//copy the env variables to an internal list of env
envc *ft_env_cpy(char **env, envc *env_new)
{
	int		i;

	i = 0;
	if (env == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		ft_lstadd_back_env(&env_new, env[i]);
		i++;
	}
	return (env_new);
}


//EXAMPLE of use:
/* int	main(int argc, char **argv, char **env)
{
	envc *env_new;

	env_new = NULL;
	env_new = ft_env_cpy(env, env_new);
	print_env_list(env_new);
	ft_lstclear_env(&env_new);
} */