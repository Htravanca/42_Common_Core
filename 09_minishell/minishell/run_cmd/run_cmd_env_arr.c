/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_env_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:35:48 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/17 19:33:24 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// free the arr and everything inside it
void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(arr[i]);
		arr[i] = NULL;
		i--;
	}
	free(arr);
	arr = NULL;
}

// just to put a value in value var
static char	*ft_this_value(t_envc *temp)
{
	if (temp->value == NULL)
		return ("");
	else
		return (temp->value);
}

// aux to convert the list into array
static char	**ft_convert_array_aux(t_envc *head, char **rt)
{
	t_envc	*temp;
	int		len;
	int		i;
	char	*value;

	temp = head;
	i = 0;
	while (temp)
	{
		value = ft_this_value(temp);
		len = ft_strlen(temp->var) + ft_strlen(value);
		rt[i] = (char *)malloc(sizeof(char) * (len + 2));
		if (!rt[i])
		{
			ft_free_arr(rt);
			return (NULL);
		}
		ft_strcpy(rt[i], temp->var);
		ft_strcat(rt[i], "=");
		ft_strcat(rt[i], value);
		i++;
		temp = temp->next;
	}
	rt[i] = NULL;
	return (rt);
}

// convert the t_envc list to an array
char	**ft_convert_array(t_envc *head)
{
	t_envc	*temp;
	int		size;
	char	**rt;

	if (head)
		ft_free_arr(get_shell()->env_arr);
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
