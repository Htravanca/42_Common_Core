/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:40:28 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:47:26 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_spaces(char *cmd, int *i)
{
	while (is_whitespace(cmd[*i]))
		(*i)++;
}

static void	validate_alnum(char c, bool *char_found)
{
	if (ft_isalnum(c) || c == '_')
		*char_found = true;
}

static bool	print_err(char c)
{
	printf("bash: syntax error near unexpected token `%c'\n", c);
	return (false);
}

bool	validate_cmd(char *cmd_line, int len, bool char_found, bool quotes)
{
	int		i;

	i = -1;
	while (i < len && cmd_line[++i])
	{
		skip_spaces(cmd_line, &i);
		validate_alnum(cmd_line[i], &char_found);
		if (is_special_char(cmd_line[i]) && !char_found && !quotes
			&& (!whitespaces(&cmd_line[i + 1]) || !cmd_line[i + 1]))
			return (print_err(cmd_line[i]));
		else if (is_special_char(cmd_line[i]) && !whitespaces(&cmd_line[i])
			&& !quotes)
			return (print_err(cmd_line[i]));
		else if (is_special_char(cmd_line[i]) && char_found == true)
		{
			char_found = false;
			if (!ft_strncmp(&cmd_line[i], ">>", 2) || !ft_strncmp(&cmd_line[i],
					"<<", 2))
				continue ;
		}
		else if (cmd_line[i] == '\"' || cmd_line[i] == '\'')
			quotes = !quotes;
	}
	return (true);
}
