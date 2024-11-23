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
	env_new = ft_env_cpy(env, env_new);

	//ft_env(env_new);
	//printf("\n\n\n");

	char **split;
	//split = ft_split("unset PATH USER SYSTEMD_EXEC_PID LaaANG", ' ');
	split = ft_split("export VAR1 PATH=olha_aqui_eu VAR10= VAR=value2 VAR123=value3 _VAR=value4 =value $VAR *VAR=value ?VAR", ' ');
	//ft_unset(split, &env_new);
	//printf("\n\n\n");
	ft_export(split, &env_new);
	print_env_list(env_new);
	ft_env(env_new);

	ft_lstclear_env(&env_new);
	ft_free_split(split);
}