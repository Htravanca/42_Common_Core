/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:53:37 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:18:14 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_variable(char **token)
{
	char	*temp;
	char	*value;
	char	*final;
	int		i;
	int		len;

	(*token)++;
	i = 0;
	while ((*token)[i] && ((*token)[i] == '_' || ft_isalnum((*token)[i])))
		i++;
	temp = ft_substr(*token, 0, i);
	*token += i;
	value = ft_get_env(temp);
	free(temp);
	if (value)
	{
		len = ft_strlen(value);
		final = ft_calloc(sizeof(char), len + 1);
		if (!final)
			return (free(value), NULL);
		trim_spaces(value, &final, &i);
		free(value);
		return (final);
	}
	return (ft_strdup(""));
}

static char	*normal_chars(char **token, char *result)
{
	int		i;
	char	*temp;
	char	*new_result;

	i = 0;
	while ((*token)[i] && (*token)[i] != '$')
		i++;
	if (i == 0)
	{
		temp = ft_substr(*token, 0, 1);
		*token += 1;
	}
	else
	{
		temp = ft_substr(*token, 0, i);
		*token += i;
	}
	if (!temp)
		return (NULL);
	new_result = ft_strjoin(result, temp);
	free(result);
	free(temp);
	return (new_result);
}

static char	*expanded_variable(char **token, char *result)
{
	char	*value;
	char	*new_result;

	new_result = NULL;
	if (!ft_strncmp(*token, "$?", 2))
	{
		value = parse_status();
		*token += 2;
	}
	else
		value = expand_variable(token);
	if (!value)
		return (NULL);
	if (result)
	{
		new_result = ft_strjoin(result, value);
		free(result);
	}
	free(value);
	return (new_result);
}

static char	*expand_token(char *token)
{
	char	*result;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	while (*token)
	{
		if (*token == '$' && *(token + 1) && !special_char(*(token + 1)))
			result = expanded_variable(&token, result);
		else
			result = normal_chars(&token, result);
		if (!result)
			return (NULL);
	}
	return (result);
}

void	expand_tokens(void)
{
	int			i;
	t_tokens	*tokens;
	char		*expanded;
	int			count;

	tokens = get_shell()->tokens;
	while (tokens)
	{
		i = -1;
		while (tokens->token && tokens->token[++i])
		{
			if (in_single_quotes(tokens->token[i]))
				continue ;
			expanded = expand_token(tokens->token[i]);
			if (expanded == NULL)
				ft_free();
			free(tokens->token[i]);
			count = check_ws(expanded);
			tokens->token[i] = expanded;
			if (count != 0)
				tokens->token = recreate_tokens(i, count, tokens->token,
						expanded);
		}
		tokens = tokens->next;
	}
}
