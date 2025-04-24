/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:57:51 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:43:02 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// free to all the list
void	ft_lstclear_env(t_envc **env_new)
{
	t_envc	*temp;

	while (*env_new)
	{
		temp = (*env_new)->next;
		free((*env_new)->var);
		if ((*env_new)->value)
			free((*env_new)->value);
		free(*env_new);
		*env_new = temp;
	}
}

// just to print the list of env
// debug only
void	print_env_list(t_envc *env)
{
	while (env)
	{
		printf("var: %s, value: %s, visible: %d\n", env->var, env->value,
			env->visible);
		env = env->next;
	}
}
