#include "pipex.h"

void	ft_free(char **var)
{
	int	i;

	i = 0;
	if (!var || !*var)
		return ;
	while (var[i] != NULL)
	{
		free(var[i]);
		i++;
	}
	free(var);
}

char	*ft_find_path(char **options, char *cmd)
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

char	*ft_path(char *cmd, char **envp)
{
	char	**options;
	char	**cmds;
	char	*pfinal;
	int		i;

	i = 0;
	pfinal = NULL;
	while (!ft_strnstr(envp[i], "PATH", 4))	// procura nos sistem variables a variavel PATH
		i++;
	options = ft_split(envp[i] + 5, ':');	// separa os paths possvies onde pode existir o cmd
	if (!options)
		return (NULL);
	cmds = ft_split(cmd, ' '); 				// necessaio para tirar o -l do "ls -l"
	if (!cmds)
		return (NULL);
	pfinal = ft_find_path(options, cmds[0]);
	ft_free(cmds);
	ft_free(options);
	return (pfinal);
}
