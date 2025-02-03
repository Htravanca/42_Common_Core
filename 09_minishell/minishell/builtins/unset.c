/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:55:54 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:42:10 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// UNSET AO t_envc
// Expected input args[0]=unset; args[n]="PATH"; args[n]="etc"; args[last]=NULL;
// Return 0 OK; -1 ERROR
void	ft_unset_env(t_envc **env, char *arg)
{
	t_envc	*temp;
	t_envc	*prev;

	temp = *env;
	prev = NULL;
	while (temp)
	{
		if (ft_strcmp(temp->var, arg) == 0)
		{
			if (prev == NULL)
				*env = temp->next;
			else
				prev->next = temp->next;
			free((temp)->var);
			if (temp->value)
				free(temp->value);
			free(temp);
			break ;
		}
		prev = temp;
		temp = temp->next;
	}
}

int	ft_unset(char **args, t_envc **env)
{
	int	i;

	i = 1;
	get_shell()->command_status = 0;
	if (!args || !args[1])
		return (-1);
	while (args[i])
	{
		ft_unset_env(env, args[i]);
		i++;
	}
	get_shell()->env_arr = ft_convert_array(get_shell()->env);
	return (0);
}
