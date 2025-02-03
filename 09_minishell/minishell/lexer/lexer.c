/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:07:30 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:48:04 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special_char(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

bool	whitespaces(char *cmd_line)
{
	int	i;

	i = 0;
	while (cmd_line[i])
	{
		if (!is_whitespace(cmd_line[i]) && !is_special_char(cmd_line[i]))
			break ;
		i++;
	}
	if (!cmd_line[i])
		return (false);
	return (true);
}

static bool	check_pipe(char *cmd, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		while (is_whitespace(cmd[i]) && i < len)
			i++;
		if (ft_isalnum(cmd[i]) || (is_special_char(cmd[i]) && cmd[i] != '|'))
			return (true);
		else if (cmd[i] == '|')
		{
			ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
			get_shell()->command_status = 2;
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_syntax(char *cmd)
{
	int		len;
	bool	char_found;
	bool	quotes;

	char_found = false;
	quotes = false;
	len = ft_strlen(cmd);
	if (closed_quotes(cmd) == -1)
		return (false);
	if (!validate_cmd(cmd, len, char_found, quotes))
	{
		get_shell()->command_status = 2;
		return (false);
	}
	return (check_pipe(cmd, len));
}
