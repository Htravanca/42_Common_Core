#include "minishell.h"

// Utility function to free a string array
void	free_string_array(char **array)
{
	if (!array)
		return ;
	for (int i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}

// Free a token structure
void	free_token(t_token *token)
{
	if (!token)
		return ;
	free_string_array(token->next->token);
	free_string_array(token->token); // Free the array of strings
	free(token);                     // Free the token structure itself
}

// Free a shell structure
void	free_shell(t_shell *shell)
{
	if (!shell)
		return ;
	free_token(shell->token);
	free(shell);
}

// Function to create a token structure
t_token	*create_token(char **tokens, short type)
{
	t_token	*new_token;
	int		token_count;

	// Allocate memory for the t_token structure
	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		perror("Failed to allocate memory for t_token");
		return (NULL);
	}
	// Count tokens
	token_count = 0;
	while (tokens[token_count])
		token_count++;
	// Allocate memory for the token array
	new_token->token = malloc((token_count + 1) * sizeof(char *));
	if (!new_token->token)
	{
		perror("Failed to allocate memory for token array");
		free(new_token);
		return (NULL);
	}
	// Copy the tokens
	for (int i = 0; i < token_count; i++)
	{
		new_token->token[i] = ft_strdup(tokens[i]);
		if (!new_token->token[i])
		{
			perror("Failed to allocate memory for token string");
			free_string_array(new_token->token);
			free(new_token);
			return (NULL);
		}
	}
	new_token->token[token_count] = NULL;
	// Initialize the remaining fields
	new_token->type = type;
	new_token->next = NULL;
	return (new_token);
}

// Function to create a shell structure
t_shell	*create_shell(t_token *token, int command_status)
{
	t_shell	*new_shell;

	// Allocate memory for the t_shell structure
	new_shell = malloc(sizeof(t_shell));
	if (!new_shell)
	{
		perror("Failed to allocate memory for t_shell");
		return (NULL);
	}
	new_shell->token = token;
	new_shell->command_status = command_status;
	return (new_shell);
}

int	main(int argc, char **argv, char **env)
{
	char	*tokens1[] = {"ls", "-l", NULL};
	char	*tokens2[] = {"cat", "cat_test", NULL};
	t_envc	*env_new;
	t_shell	*shell;
	t_token	*token1;
	t_token	*token2;

	env_new = NULL;
	shell = NULL;
	token1 = NULL;
	token2 = NULL;
	(void)argc;
	(void)argv;
	// Create the first token
	token1 = create_token(tokens1, 1);
	if (!token1)
		return (EXIT_FAILURE);
	// Create the second token
	token2 = create_token(tokens2, 1);
	if (!token2)
	{
		free_token(token1); // Free token1 before returning
		return (EXIT_FAILURE);
	}
	// Link the tokens
	token1->next = token2;
	// Create a shell structure
	shell = create_shell(token1, 0);
	if (!shell)
	{
		free_token(token2); // Free token2
		free_token(token1); // Free token1
		return (EXIT_FAILURE);
	}
	// Copy the environment list
	env_new = ft_env_cpy(env, env_new);
	// Simulate command execution
	ft_runcmd(shell, env_new);
	// Cleanup
	printf("--- Cleaning up ---\n");
	ft_lstclear_env(&env_new); // Free the env list
	free_shell(shell);         // Free the shell and tokens
	return (EXIT_SUCCESS);
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
	split = ft_split("export VAR1 PATH=asserere VAR10= VAR=value2 VAR123=value3 _VAR=value4 =value $VAR *VAR=value ?VAR",
			' ');
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

	printf("\n--- TEST 2: Export with edge cases (e.g., _VAR, VAR=, no value,
		special chars) ---\n");
	split = ft_split("export _VAR=value3 VAR= VAR123=value123 ?VAR=value4 =value *VAR=value",
			' ');
	ft_export(split, &env_new);
	ft_free_split(split);
	print_env_list(env_new);

	printf("\n--- TEST 3: Export invalid variables (e.g.,
		starting with non-alphanumeric, $, ?) ---\n");
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
