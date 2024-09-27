#include "pipex.h"

void	ft_free_arr(char **var)
{
	int	i;

	i = 0;
	if (!var)
		return ;
    printf("aqii\n");
	while (var[i] != NULL)
	{
		free(var[i]);
		i++;
	}
    printf("aqii\n");
	free(var);
}

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

char **ft_options(void)
{
    char **options;

    options = (char **)malloc(3 * sizeof(char *));
    if (!options)
        exit (1);
    options[0] = ft_strdup("/usr/bin");
    options[1] = ft_strdup("/bin");
    options[2] = NULL;
    return (options);
}

char	*ft_path(char **cmdsarr, char **envp)
{
	char	**options;
	char	*pfinal;
	int		i;

	i = 0;
	pfinal = NULL;
    if (!*envp)
        options = ft_options();
    else
    {
        while (!ft_strnstr(envp[i], "PATH", 4))
		    i++;
	    options = ft_split(envp[i] + 5, ':');
	    if (!options)
		    return (NULL);
    }
	pfinal = ft_find_path(options, cmdsarr[0]);
	ft_free_arr(options);
	return (pfinal);
}

int main (int argc, char **argv, char **envp)
{
    char **cmdsarr;
    char *path;

    cmdsarr = ft_split_adapt(argv[2], ' ');
	ft_split_result(cmdsarr);
     printf("%s\n", envp[0]);
	path = ft_path(cmdsarr, envp);
    printf("%s\n", path);
}

