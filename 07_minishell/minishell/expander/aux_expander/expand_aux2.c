/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_aux2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:48:23 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:18:05 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quotes(char *exp)
{
	int	i;

	i = 0;
	while (exp[i])
	{
		if (exp[i] == '\"')
			return (0);
		i++;
	}
	return (1);
}

int	check_ws(char *exp)
{
	int	i;
	int	j;

	if (!exp)
		return (0);
	if (check_quotes(exp) == 0)
		return (0);
	i = 0;
	j = 0;
	while (exp[i])
	{
		if (is_whitespace(exp[i]))
			j++;
		i++;
	}
	return (j);
}

static char	**recreate_tokens2(char **new, char *exp, char **tok, int i)
{
	char	**exp_arr;
	int		j;
	int		k;
	int		l;

	exp_arr = ft_split(exp, ' ');
	free(exp);
	if (!exp_arr)
		return (NULL);
	j = 0;
	k = i;
	l = i;
	while (exp_arr[j])
		new[k++] = exp_arr[j++];
	while (tok[++i])
		new[k++] = tok[i];
	new[k] = NULL;
	if (l > 0)
		free(tok);
	if (exp_arr)
		free(exp_arr);
	return (new);
}

char	**recreate_tokens(int i, int count, char **tok, char *exp)
{
	char	**new_tokens;
	int		j;
	int		k;

	j = count_tokens(tok);
	count += 1 + j;
	new_tokens = ft_calloc(sizeof(char *), count);
	if (!new_tokens)
		ft_free();
	k = -1;
	while (++k < i)
		new_tokens[k] = tok[k];
	new_tokens = recreate_tokens2(new_tokens, exp, tok, i);
	if (!new_tokens)
		ft_free();
	return (new_tokens);
}

int	special_char(char c)
{
	if (c == '/' || c == '.' || c == ',' || c == ':' || c == '\"' || c == '\'')
		return (1);
	return (0);
}
