
// CD BUILTINS
// Expected input args[0]=cd; args[1]=Relative or absolute path; args[2]=NULL
// Return 0 Ok; -1 Error
// Falta atualizar os ENV com o novo PWD e o OLD_PWD <--------------------------------------------
int	ft_cd(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
		printf("Expected argument to \"cd\"\n");
	else if (i == 2)
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (-1);
		}
		return (0);
	}
	else
		printf("cd: too many arguments\n");
	return (-1);
}



// ECHO BUILTINS
// Expected input args[0]=echo; args[1]=-n (opcional); args[n]="something"; args[last]=NULL;
// Return 0 Ok; -1 Error
int	ft_echo(char **args)
{
	int	newline;
	int	i;

	newline = 1;
	i = 1;
	if (args[i] && ft_strcmp(args[i], "-n") == 0)
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}


//COPY ENV TO INTERNAL ARRAY
// Expected input ENV(environment varibles) <--------------------------------------------
// Return env_copy Ok; NULL Error
void	ft_free_envc(char **envc)
{
	int	i;

	i = 0;
	if (envc == NULL)
		return ;
	while (envc[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(envc[i]);
		i--;
	}
	free(envc);
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


//UNSET AO ENVC
// Expected input args[0]=unset; args[n]="PATH"; args[n]="etc"; args[last]=NULL;
// Return new env_copy with unset vars; NULL ERROR
char	**ft_unset_env(char **envc, int j)
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
			if ((new_envc[aux] = ft_strdup(envc[i])) == NULL)
				return (ft_free_envc(envc), ft_free_envc(new_envc), NULL);
			aux++;
		}
		i++;
	}
	new_envc[aux] = NULL;
	return (ft_free_envc(envc), new_envc);
}

char	**ft_unset(char **args, char **envc)
{
	int	i;
	int	j;

	i = 1;
	if (args == NULL)
		return (envc);
	while (args[i] != NULL)
	{
		j = 0;
		while (envc && envc[j] && !ft_strnstr(envc[j], args[i],
				ft_strlen(args[i])))
			j++;
		if (envc[j])
		{
			envc = ft_unset_env(envc, j);
			if (envc == NULL)
				return (NULL);
		}
		i++;
	}
	return (envc);
}


//EXPORT ainda por acabar

char **ft_sep_export(char **split_arg, char *arg)
{
	int j;

	j = 0;
	while (arg[j] && arg[j] != '=')
		j++;
	printf("%c\t%d\n",arg[j], j);
	if(arg[j] == '=')
	{
		split_arg[0] = (char *)malloc(sizeof(char *) * (j + 1));
		j = 0;
		while (arg[j] && arg[j] != '=')
		{
			split_arg[0][j] = arg[j];
			j++;
		}
		split_arg[0][j] = '\0';
		printf("split_arg[0]:%s",split_arg[0]);
	}
	else
	{

	}

}

char **ft_export(char **args, char **envc)
{
	int i;
	char **split_arg;

	i = 1;
	//split_arg = (char *)malloc(sizeof(char *) * 3);
	while (args[i] != NULL)
	{
		//split do arg da varivel antes e depois do primeiro '='
		split_arg = ft_sep_export(split_arg, args[i]);
		//ver ser o nome da VAR valido

		i++;
	}
	
	
}



