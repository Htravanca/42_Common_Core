/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:56:09 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:41:33 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ECHO BUILTINS
// Expected input args[0]=echo; args[1]=-n (opcional);
// args[n]="something"; args[last]=NULL;
// Return 0 Ok; -1 Error
static int	ft_multiplen(char *str)
{
	int	j;

	j = 1;
	while (str[j] == 'n')
		j++;
	if (str[j] != '\0')
		return (-1);
	return (0);
}

int	ft_echo(char **args, int out)
{
	int	newline;
	int	i;

	newline = 1;
	i = 1;
	while (args[i] && args[i][0] == '-' && args[i][1] == 'n'
		&& ft_multiplen(args[i]) == 0)
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], out);
		if (args[i + 1])
			ft_putstr_fd(" ", out);
		i++;
	}
	if (newline)
		ft_putstr_fd("\n", out);
	get_shell()->command_status = 0;
	return (0);
}
