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
	t_envc	*env_new = NULL;
	t_token *token = NULL;

	(void)argc;
	(void)argv;

	// Step 1: Copy the system environment variables into a custom linked list
	env_new = ft_env_cpy(env, env_new);

	ft_runcmd(token, env_new);

	printf("\n--- TEST 10: Clean-up (Free all memory) ---\n");
	ft_lstclear_env(&env_new);
	print_env_list(env_new); // Should print nothing
}

/* int	main(int argc, char **argv, char **env)
{
	//char **envc;
	envc *env_new;

	env_new = NULL;
	(void)argc;
	(void)argv;
	env_new = ft_env_cpy(env, env_new);

	char **split;
	split = ft_split("export VAR1 PATH=asserere VAR10= VAR=value2 VAR123=value3 _VAR=value4 =value $VAR *VAR=value ?VAR", ' ');
	ft_export(split, &env_new);
	ft_env(env_new);

	ft_lstclear_env(&env_new);
	ft_free_split(split);
} */
/* 
int	main(int argc, char **argv, char **env)
{
	envc	*env_new = NULL;
	char	**split;

	(void)argc;
	(void)argv;

	// Step 1: Copy the system environment variables into a custom linked list
	env_new = ft_env_cpy(env, env_new);

	printf("\n--- TEST 1: Export valid variables ---\n");
	split = ft_split("export VAR1=value1 VAR2=value2", ' ');
	ft_export(split, &env_new);
	ft_free_split(split);
	print_env_list(env_new);

	printf("\n--- TEST 2: Export with edge cases (e.g., _VAR, VAR=, no value, special chars) ---\n");
	split = ft_split("export _VAR=value3 VAR= VAR123=value123 ?VAR=value4 =value *VAR=value", ' ');
	ft_export(split, &env_new);
	ft_free_split(split);
	print_env_list(env_new);

	printf("\n--- TEST 3: Export invalid variables (e.g., starting with non-alphanumeric, $, ?) ---\n");
	split = ft_split("export $VAR ?VAR 123VAR invalid-Var=value", ' ');
	ft_export(split, &env_new);
	ft_free_split(split);
	print_env_list(env_new);

	printf("\n--- TEST 4: Overwriting existing variables ---\n");
	split = ft_split("export VAR1=newvalue1 VAR2=newvalue2", ' ');
	ft_export(split, &env_new);
	ft_free_split(split);
	print_env_list(env_new);

	printf("\n--- TEST 5: Handling empty input ---\n");
	split = ft_split("export", ' ');
	ft_export(split, &env_new);
	ft_free_split(split);
	print_env_list(env_new);

	printf("\n--- TEST 6: Exporting without value and making it invisible in env ---\n");
	split = ft_split("export VAR5", ' ');
	ft_export(split, &env_new);
	ft_free_split(split);
	print_env_list(env_new);
	ft_env(env_new); // Check visibility in `env`

	printf("\n--- TEST 7: Unset variables ---\n");
	split = ft_split("unset VAR1 VAR2 _VAR VAR10", ' ');
	ft_unset(split, &env_new);
	ft_free_split(split);
	print_env_list(env_new);
	ft_env(env_new);

	printf("\n--- TEST 8: Export variables with '=' only (visibility edge case) ---\n");
	split = ft_split("export VAR6= VAR7=", ' ');
	ft_export(split, &env_new);
	ft_free_split(split);
	print_env_list(env_new);

	printf("\n--- TEST 9: Handle invalid '=' placement (e.g., =value) ---\n");
	split = ft_split("export =value", ' ');
	ft_export(split, &env_new);
	ft_free_split(split);
	print_env_list(env_new);

	printf("\n--- TEST 10: Clean-up (Free all memory) ---\n");
	ft_lstclear_env(&env_new);
	print_env_list(env_new); // Should print nothing
} */
