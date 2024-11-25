#include "minishell.h"

// free to all the list
void	ft_lstclear_env(envc **env_new)
{
	envc	*temp;

	while (*env_new)
	{
		temp = (*env_new)->next;
		free((*env_new)->var);
		if ((*env_new)->value)
			free((*env_new)->value);
		free(*env_new);
		*env_new = temp;
	}
}

// just to print the list of env
// debug only
void	print_env_list(envc *env)
{
	while (env)
	{
		printf("var: %s, value: %s, visible: %d\n", env->var, env->value,
			env->visible);
		env = env->next;
	}
}
