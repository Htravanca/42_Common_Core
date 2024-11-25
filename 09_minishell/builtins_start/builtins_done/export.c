#include "../minishell.h"

// UNSET to ENVC
// Expected input args[0]=export; args[n]="PATH"; args[n]="etc"; args[last]=NULL;
// Return 0 OK; -1 ERROR
int	ft_export_valid(char **arg_sep)
{
	int	i;
	int	valid;

	i = 0;
	valid = -1;
	if (ft_isalpha(arg_sep[0][0]) || arg_sep[0][0] == '_')
		valid = 1;
	while (arg_sep[0][i])
	{
		if (!(ft_isalpha(arg_sep[0][i]) || ft_isdigit(arg_sep[0][i])
				|| arg_sep[0][i] == '_'))
			valid = -1;
		i++;
	}
	return (valid);
}

void	ft_find_lstenv(char **arg_sep, envc *temp)
{
	printf("encontrei na lista\n");
	free(temp->value);
	if (arg_sep[1])
	{
		if (arg_sep[2])
			temp->value = ft_strdup(arg_sep[2]);
		else
			temp->value = NULL;
		temp->visible = 1;
	}
	else
	{
		temp->value = NULL;
		temp->visible = 0;
	}
}

void	ft_lstenv_visible(char **arg_sep, envc **env)
{
	envc	*temp;

	temp = *env;
	while (temp)
	{
		if (ft_strcmp(temp->var, arg_sep[0]) == 0)
			temp->visible = 0;
		temp = temp->next;
	}
}

int	ft_export_arg(char **arg_sep, char *args, envc **env)
{
	envc	*temp;
	int		find;

	temp = *env;
	find = 0;
	while (temp)
	{
		if (ft_strcmp(temp->var, arg_sep[0]) == 0)
		{
			ft_find_lstenv(arg_sep, temp);
			find = 1;
		}
		temp = temp->next;
	}
	if (find == 0)
	{
		ft_lstadd_back_env(env, args);
		if (!arg_sep[1])
			ft_lstenv_visible(arg_sep, env);
	}
	return (1);
}

static void	ft_free_sep(char **arg_sep)
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

int	ft_export(char **args, envc **env)
{
	int		i;
	char	**arg_sep;
	int		valid;
	int		k;

	i = 1;
	if (!args || !args[1])
		return (-1);
	while (args[i])
	{
		arg_sep = ft_sep_args(args[i]);  
			// separate VAR=adasd into [0]=VAR [1]="=" [2]=adasd [3]=NULL
		valid = ft_export_valid(arg_sep); // validates it
		if (valid == -1)
		{
			printf("------------------>DEU MERDA\n");
			ft_free_sep(arg_sep);
			i++;
			continue ; //->ver se e necessario incremetar o i++ no while
		}
		ft_export_arg(arg_sep, args[i], env); // add it to the list
		k = 0;
		while (arg_sep[k])
		{
			printf("arg_sep[%d]:%s\n", k, arg_sep[k]);
			k++;
		}
		printf("---------\n\n");
		ft_free_sep(arg_sep); // free the allocated memory
		i++;
	}
	return (0);
}
