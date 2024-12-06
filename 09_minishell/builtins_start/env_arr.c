#include "minishell.h"

static char	**ft_convert_array_aux(t_envc *head, char **rt)
{
	t_envc	*temp;
	int		len;
	int		i;

	temp = head;
	i = 0;
	while (temp)
	{
		len = ft_strlen(temp->var) + ft_strlen(temp->value);
		rt[i] = (char *)malloc(sizeof(char) * (len + 2));
		if (!rt[i])
		{
			while (--i >= 0)
				free(rt[i]);
			free(rt);
			return (NULL);
		}
		ft_strcpy(rt[i], temp->var);
		ft_strcat(rt[i], "=");
		ft_strcat(rt[i], temp->value);
		i++;
		temp = temp->next;
	}
	rt[i] = NULL;
	return (rt);
}

char	**ft_convert_array(t_envc *head)
{
	t_envc	*temp;
	int		size;
	char	**rt;

	temp = head;
    size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	rt = (char **)malloc((size + 1) * sizeof(char *));
	if (!rt)
		return (NULL);
	rt[size] = NULL;
	return (ft_convert_array_aux(head, rt));
}

void	ft_free_env_arr(char **env)
{
	int	i;

	i = 0;
	if (env == NULL)
		return ;
	while (env[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(env[i]);
		i--;
	}
	free(env);
}

