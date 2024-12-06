#include "../minishell.h"

// ADDS Vars to ENVC
// Expected input args[0]=export; args[n]="PATH"; args[n]="etc"; 
// 		args[last]=NULL;
// Return 0 OK; -1 ERROR

// check if the arg is valid or not; -1 Error; 1 ok
int	ft_export_valid(char **arg_sep)
{
	int	i;

	i = 0;
	if (!arg_sep || !arg_sep[0])
		return (-1);
	if (!ft_isalpha(arg_sep[0][0]) && arg_sep[0][0] != '_')
		return (-1);
	while (arg_sep[0][i])
	{
		if (!(ft_isalpha(arg_sep[0][i]) || ft_isdigit(arg_sep[0][i])
				|| arg_sep[0][i] == '_'))
			return (-1);
		i++;
	}
	return (1);
}

// updates the value of the var in the list
void	ft_find_lstenv(char **arg_sep, t_envc *temp)
{
	if (arg_sep[1])
	{
		if (temp->value)
			free(temp->value);
		if (arg_sep[2])
			temp->value = ft_strdup(arg_sep[2]);
		else
			temp->value = NULL;
		temp->visible = 1;
	}
}

// make the var not visible to env cmd
void	ft_lstenv_visible(char **arg_sep, t_envc **env)
{
	t_envc	*temp;

	temp = *env;
	while (temp)
	{
		if (ft_strcmp(temp->var, arg_sep[0]) == 0)
			temp->visible = 0;
		temp = temp->next;
	}
}

// checks if the var is in the list or not
int	ft_export_arg(char **arg_sep, char *args, t_envc **env)
{
	t_envc	*temp;
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

// Expected input args[0]=export; args[n]="PATH=lalala"; args[n]="etc"; 
//		args[last]=NULL;
// Return 0 OK; -1 ERROR
int	ft_export(char **args, t_envc **env)
{
	int		i;
	char	**arg_sep;
	int		valid;
	

	i = 1;
	if (!args)
		return (-1);
	if (!args[1])
		ft_print_env_sorted(*env);
	while (args[i])
	{
		arg_sep = ft_sep_args(args[i]); // separate VAR=adasd into [0]=VAR [1]="=" [2]=adasd [3]=NULL
		valid = ft_export_valid(arg_sep); // validates it
		if (valid == -1)
		{
			printf("export: '%s': not a valid identifier\n", args[i]);
			ft_free_sep(arg_sep);
			i++;
			continue ; //->ver se e necessario incremetar o i++ no while
		}
		ft_export_arg(arg_sep, args[i], env); // add it to the list
		ft_free_sep(arg_sep); // free the allocated memory
		i++;
	}
	return (0);
}

//int		k;
/* k = 0;
		while (arg_sep[k])
		{
			printf("arg_sep[%d]:%s\n", k, arg_sep[k]);
			k++;
		}
		printf("---------\n\n"); */
