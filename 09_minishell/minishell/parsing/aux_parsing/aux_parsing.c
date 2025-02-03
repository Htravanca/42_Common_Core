/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:44:41 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:44:41 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	count_tokens(char **arr_split)
{
	int	i;

	i = 0;
	if (!arr_split[i])
		return (0);
	while (arr_split[i])
		i++;
	return (i);
}

int	check_builtin(char *token)
{
	if (!ft_strcmp(token, "echo"))
		return (1);
	if (!ft_strcmp(token, "cd"))
		return (2);
	if (!ft_strcmp(token, "pwd"))
		return (3);
	if (!ft_strcmp(token, "export"))
		return (4);
	if (!ft_strcmp(token, "unset"))
		return (5);
	if (!ft_strcmp(token, "exit"))
		return (6);
	if (!ft_strcmp(token, "env"))
		return (7);
	return (0);
}
