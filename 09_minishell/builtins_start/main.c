#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

#define BUFFER_PWD 4096

// ENV Builtins
int	ft_env(char **env)
{
	int	i;

	i = 0;
	if (env == NULL)
		return (-1);
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

int	ft_pwd(void)
{
	char	buffer[BUFFER_PWD];

	if (getcwd(buffer, BUFFER_PWD) != NULL)
	{
		printf("%s\n", buffer);
		return (0);
	}
	else
	{
		perror("pwd");
		return (-1);
	}
}

void	ft_free_envc(char **envc)
{
	int i;

	i = 0;
	while (envc[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(envc[i]);
		i--;
	}
	free (envc);
}

char	**ft_env_cpy(char **env)
{
	int		i;
	char	**envc;

	envc = NULL;
	i = 0;
	if (env == NULL)
		return (NULL);
	while (env[i] != NULL)
		i++;
	envc = (char **)malloc(sizeof(char *) * (i + 1));
	if (envc == NULL)
		return (NULL);
	i = 0;
	while (env[i] != NULL)
	{
		envc[i] = ft_strdup(env[i]);
		if (envc[i] == NULL)
		{
			ft_free_envc(envc);
			return (NULL);
		}
		i++;
	}
	envc[i] = NULL;
	return (envc);
}

char **ft_unset_env(char **envc, int j)
{
	int		i;
	int		aux;
	char	**new_envc;

	new_envc = NULL;
	i = 0;
	aux = 0;
	while (envc[i] != NULL)
		i++;
	new_envc = (char **)malloc(sizeof(char *) * (i));
	if (new_envc == NULL)
		return (NULL);
	i = 0;
	while (envc[i] != NULL)
	{
		if (i != j)
		{
			new_envc[aux] = ft_strdup(envc[i]);
			if (new_envc[aux] == NULL)
			{
				ft_free_envc(new_envc);
				ft_free_envc(envc);
				return (NULL);
			}
			aux++;
		}
		i++;
	}
	new_envc[aux] = NULL;
	ft_free_envc(envc);
	return (new_envc);
}

char **ft_unset(char **args, char **envc)
{
	int i;
	int j;

	i = 1;
	while (args[i] != NULL)
	{
		j = 0;
		while (envc && envc[j] && !ft_strnstr(envc[j], args[i], ft_strlen(args[i])))
			j++;
		if (envc[j])
		{
			envc = ft_unset_env(envc, j);
		}
		if (envc == NULL)
			return (NULL);
		i++;
	}
	return (envc);
}

int	main(int argc, char **argv, char **env)
{
	char **envc;

	(void)argc;
	(void)argv;
	envc = ft_env_cpy(env);
	//ft_env(envc);

	printf("\n\n\n\n");
	char **split;
	split = ft_split("unset USER PWD", ' ');
	envc = ft_unset(split, envc);
	ft_env(envc);

	// ft_pwd();
	ft_free_envc(split);
	ft_free_envc(envc);
}