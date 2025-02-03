/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:55:36 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:42:07 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BUFFER_PWD 4096

// PWD BUILTINS
// Expected input void
// Return 0 Ok; -1 Error
int	ft_pwd(int out)
{
	char	buffer[BUFFER_PWD];

	if (getcwd(buffer, BUFFER_PWD) != NULL)
	{
		ft_putstr_fd(buffer, out);
		ft_putstr_fd("\n", out);
		get_shell()->command_status = 0;
		return (0);
	}
	else
	{
		ft_putstr_fd("PWD: Error\n", out);
		get_shell()->command_status = 1;
		return (-1);
	}
}
