#include "../minishell.h"

// counts the words to allocate memory to the separed args
static int	ft_count_word(char *args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (args[i])
	{
		while (args[i] && args[i] != '=')
		{
			count = 1;
			i++;
		}
		if (args[i] && args[i] == '=')
		{
			count = 2;
			i++;
		}
		while (args[i])
		{
			count = 3;
			while (args[i])
				i++;
		}
	}
	return (count);
}

// alocate memory and return the VAR part of the string
static char	*ft_word_var(char *args)
{
	int		i;
	char	*var;

	i = 0;
	while (args[i] && args[i] != '=')
		i++;
	var = (char *)malloc((i + 1) * sizeof(char));
	if (!var)
		return (NULL);
	i = 0;
	while (args[i] && args[i] != '=')
	{
		var[i] = args[i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

// alocate memory and return the VALUE part of the string
static char	*ft_word_value(char *args)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	j = 0;
	while (args[i] && args[i] != '=')
		i++;
	j = ft_strlen(args);
	var = (char *)malloc(((j - i) + 1) * sizeof(char));
	if (!var)
		return (NULL);
	j = 0;
	i++;
	while (args[i])
	{
		var[j] = args[i];
		j++;
		i++;
	}
	var[j] = '\0';
	return (var);
}

// separate string into a split
char	**ft_sep_args(char *args)
{
	char	**rt;
	int		words;

	words = ft_count_word(args);
	rt = (char **)malloc((words + 1) * sizeof(char *));
	if (!rt)
		return (NULL);
	rt[words] = NULL;
	if (words >= 1)
		rt[0] = ft_word_var(args);
	if (words >= 2)
		rt[1] = ft_strdup("=");
	if (words == 3)
		rt[2] = ft_word_value(args);
	return (rt);
}

// free the alloc memory of the arg_sep
void	ft_free_sep(char **arg_sep)
{
	int	i;

	i = 0;
	if (arg_sep == NULL)
		return ;
	while (arg_sep[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(arg_sep[i]);
		i--;
	}
	free(arg_sep);
}
