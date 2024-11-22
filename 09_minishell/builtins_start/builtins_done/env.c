#include "../minishell.h"

// ENV Builtins
// input envc (linked list copy of env)
// output 0 ok; -1 error
int	ft_env(envc *env)
{
	if (env == NULL)
		return (-1);
	while (env)
	{
		if (env->visible == 1)
			printf("%s=%s\n", env->var, env->value);
		env = env->next;
	}
	return (0);
}
