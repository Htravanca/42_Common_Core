/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:56:06 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:41:35 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ENV Builtins
// input envc (linked list copy of env)
// output 0 ok; -1 error
int	ft_env(t_envc *env, int out)
{
	if (env == NULL)
		return (-1);
	while (env)
	{
		if (env->visible == 1 && env->value != NULL)
		{
			ft_putstr_fd(env->var, out);
			ft_putstr_fd("=", out);
			ft_putstr_fd(env->value, out);
			ft_putstr_fd("\n", out);
		}
		if (env->visible == 1 && env->value == NULL)
		{
			ft_putstr_fd(env->var, out);
			ft_putstr_fd("=\n", out);
		}
		env = env->next;
	}
	get_shell()->command_status = 0;
	return (0);
}
