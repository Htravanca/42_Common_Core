#include "minishell.h"

// RETURN a string with VAR
static char	*ft_env_var(char *env)
{
	int		i;
	char	*var;

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

// RETURN a string with VALUE
static char	*ft_env_value(char *env)
{
	int		i;
	int		value_len;
	char	*value;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	if (!env[i] || env[i + 1] == '\0')
		return (ft_strdup(""));
	value_len = ft_strlen(env) - (i + 1);
	value = (char *)malloc(sizeof(char) * (value_len + 1));
	if (!value)
		return (NULL);
	i++;
	ft_strlcpy(value, &env[i], value_len + 1);
	return (value);
}

// Create a new node of list
static t_envc	*ft_lstnew_env(char *env)
{
	t_envc	*new;

	new = malloc(sizeof(t_envc)); // USAR QUI o CALLOC
	if (!new)
		return (NULL);
	new->var = ft_env_var(env);
	new->value = ft_env_value(env);
	new->visible = 1;
	new->next = NULL;
	return (new);
}

// Add the new node to the back of the list
void	ft_lstadd_back_env(t_envc **env_new, char *env)
{
	t_envc	*temp;
	t_envc	*new;

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

// copy the env variables to an internal list of env
t_envc	*ft_env_cpy(char **env, t_envc *env_new)
{
	int	i;

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

// EXAMPLE of use:
/* int	main(int argc, char **argv, char **env)
{
	t_envc *env_new;

	env_new = NULL;
	env_new = ft_env_cpy(env, env_new);
	print_env_list(env_new);
	ft_lstclear_env(&env_new);
} */