/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:29:24 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:17:58 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_env(char *var)
{
	t_envc	*envc;
	char	*expanded;

	envc = get_shell()->env;
	expanded = NULL;
	while (envc)
	{
		if (!ft_strcmp(envc->var, var))
		{
			expanded = ft_strdup(envc->value);
			break ;
		}
		envc = envc->next;
	}
	return (expanded);
}

int	in_single_quotes(char *str)
{
	return (str[0] == '\'' && str[ft_strlen(str) - 1] == '\'');
}

char	*trim_spaces(char *result, char **final, int *i)
{
	int	j;

	*i = 0;
	j = 0;
	if (*result == '\'' || *result == '\"')
	{
		*final[j++] = *result;
		result++;
		while (result[*i] && is_whitespace(result[*i]))
			(*i)++;
	}
	while (result[*i])
	{
		if (is_whitespace(result[*i]) && j > 1)
		{
			while (is_whitespace(result[*i]))
				(*i)++;
			if (result[*i] && result[*i] != (*final)[0])
				(*final)[j++] = 32;
		}
		else if (!is_whitespace(result[*i]))
			(*final)[j++] = result[(*i)++];
	}
	(*final)[j] = 0;
	return (*final);
}

char	*parse_status(void)
{
	char	*cmd_status;

	cmd_status = ft_itoa(get_shell()->command_status);
	if (!cmd_status)
		return (NULL);
	return (cmd_status);
}
