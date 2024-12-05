#include "minishell.h"

// token = {"ls", "-l", NULL};

/* static char	*ft_find_path(char **options, char *cmd)
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
		ft_free_arr(options);
	}
	return (pfinal);
}


static void	ft_execute(char *argv, char **envp)
{
	char	*path;

	path = ft_path(argv, envp, argv);
	if (!path)
	{
		perror("Command not found");
		exit(127);
	}
	execve(path, argv, envp);
	perror("Error executing the cmd");
	free(path);
	exit(1);
}
 */


void	ft_runcmd(t_token *cmd, envc *head)
{
	char	**env;
	int		i;

	(void)cmd;
	env = ft_convert_array(head);
	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	/* if (cmd->type == 1) //normal exec
	{
		//fork
		ft_execute(cmd->token, head);
		//waitpid
	}
	if (cmd->type == 2) //REDIR
	{
	}
	if (cmd->type == 3) // LIST
	{
	}
	if (cmd->type == 4 //PIPE
	)
	{
	}
	if (cmd->type == 5 //BACK
	)
	{
	} */
    ft_free_env_arr(env);
}
