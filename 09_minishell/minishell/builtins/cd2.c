/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:56:45 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/29 21:41:31 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_go_home(int out)
{
	t_envc	*temp;

	temp = get_shell()->env;
	while (temp)
	{
		if (ft_strcmp(temp->var, "HOME") == 0)
		{
			if (chdir(temp->value) != 0)
			{
				ft_putstr_fd(temp->value, out);
				ft_putstr_fd(": No such file or directory\n", out);
				get_shell()->command_status = 1;
				return (-1);
			}
			ft_change_pwd(get_shell()->env, out);
			return (0);
		}
		temp = temp->next;
	}
	if (temp == NULL)
		ft_putstr_fd("cd: HOME not set\n", out);
	return (-1);
}
