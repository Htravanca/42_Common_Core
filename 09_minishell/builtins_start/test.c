#include "minishell.h"

static char	*ft_find_path(char **options, char *cmd)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	*pfinal;

	i = 0;
	pfinal = NULL;
	while (options[i])
	{
		temp = ft_strjoin(options[i], "/");
		temp2 = ft_strjoin(temp, cmd);
		free(temp);
		if (access(temp2, F_OK) == 0)
		{
			pfinal = ft_strdup(temp2);
			free(temp2);
			break ;
		}
		free(temp2);
		i++;
	}
	return (pfinal);
}

int	ft_check_path(char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}

char	**ft_options(void)
{
	char	**options;

	options = (char **)malloc(3 * sizeof(char *));
	if (!options)
		exit(1);
	options[0] = ft_strdup("/usr/bin");
	options[1] = ft_strdup("/bin");
	options[2] = NULL;
	return (options);
}

char	*ft_path(char **cmdsarr, char **envp, char *path)
{
	char	**options;
	char	*pfinal;
	int		i;

	i = 0;
	pfinal = NULL;
	options = NULL;
	if (ft_check_path(path))
		return (path);
	while (envp && envp[i] && !ft_strnstr(envp[i], "PATH", 4))
		i++;
	if (i == 0)
		options = ft_options();
	else if (envp[i] && ft_strnstr(envp[i], "/usr/bin", ft_strlen(envp[i])))
	{
		options = ft_split(envp[i] + 5, ':');
		if (!options)
			return (NULL);
	}
	if (options != NULL && options[0] != NULL)
	{
		pfinal = ft_find_path(options, cmdsarr[0]);
		ft_free_env_arr(options);
	}
	return (pfinal);
}

static void	ft_execute(t_shell *shell, char **envp , t_envc *head, t_token *token)
{
	char	*path;

	path = ft_path(token->token, envp, token->token[0]);
	if (!path)
	{
		printf("%s: command not found\n",token->token[0]);
		ft_lstclear_env(&head); //free everything in the program so far
		ft_free_env_arr(envp);
		free_shell(shell);
		exit(127);
	}
	execve(path, token->token, envp);
	perror("Error executing the cmd");
	free(path);
	ft_lstclear_env(&head); //free everything in the program so far
	ft_free_env_arr(envp);
	free_shell(shell);
	exit(1);
}

int	ft_handle_error(int val, const char *msg)
{
	if (val < 0)
	{
		perror(msg);
		exit(1);
	}
	return (val);
}

int ft_runcmd2(t_shell *shell, char **env, t_envc *head, t_token *token)
{
	int pid1;
	int	status1;

	if (token->type == 1) //normal exec
	{
		pid1 = ft_handle_error(fork(), "Fork error");
		if (pid1 == 0)
			ft_execute(shell, env, head, token);
		waitpid(pid1, &status1, 0);
		if (WEXITSTATUS(status1) != 0)
		{
			shell->command_status = WEXITSTATUS(status1);
			return (-1);
		}
	}/*
	 if (token->type == 2) //REDIR
	{
	}
	*/
	if (token->type == 3) // LIST
	{
		pid1 = ft_handle_error(fork(), "Fork error");
		if (pid1 == 0)
			ft_execute(shell, env, head, token);
		waitpid(pid1, &status1, 0);
		shell->command_status = WEXITSTATUS(status1);
	}
	/*if (token->type == 4 //PIPE
	)
	{
	}
	if (token->type == 5 //BACK
	)
	{
	} */
	return (0);
}

void	ft_runcmd(t_shell *shell, t_envc *head)
{
	char	**env;
	t_token *temp;

	env = ft_convert_array(head);
	shell->command_status = 0;
	temp = shell->token;
	while (temp)
	{
		if (ft_runcmd2(shell, env, head, temp) == -1)
			break ;
		temp = temp->next;
	}
	printf("\n\ncommand status:%d", shell->command_status);
	ft_free_env_arr(env);
}
