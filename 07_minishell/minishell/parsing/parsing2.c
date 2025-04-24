/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:13:41 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:13:42 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_input_aux(char *replaced)
{
	if (!replaced)
		return (-1);
	return (0);
}

static void	populate_lst2(t_tokens *tokens)
{
	int	type;
	int	i;
	int	j;

	i = 0;
	while (tokens->token[i])
	{
		type = get_type(tokens->token[i]);
		if (type)
		{
			populate_redir(&tokens->token[i], tokens, type);
			j = i + 1 + (tokens->token[i + 1] != NULL);
			while (tokens->token[j])
				tokens->token[i++] = tokens->token[j++];
			tokens->token[i] = NULL;
			i = 0;
		}
		else
			i++;
	}
}

void	populate_lst(char **arr_split)
{
	t_tokens	*lsttokens;

	lsttokens = ft_lsttoken(arr_split);
	if (!lsttokens)
	{
		ft_free_err(arr_split, "Error creating list.");
		exit(1);
	}
	if (!get_shell()->tokens)
		get_shell()->tokens = lsttokens;
	else
		ft_tokensadd_back(&get_shell()->tokens, lsttokens);
	populate_lst2(lsttokens);
	if (lsttokens->token[0])
		lsttokens->is_builtin = check_builtin(lsttokens->token[0]);
}

/* realloc mem,
	including 1 extra byte for the new char
	and another one for the null terminator */
char	*add_char(char *curr, char c)
{
	int		len;
	char	*ret;

	len = 0;
	if (curr && *curr)
		len = ft_strlen(curr);
	ret = ft_calloc(sizeof(char), len + 1 + 1);
	if (!ret)
		return (NULL);
	if (len > 0)
		ft_strlcpy(ret, curr, len + 1);
	free(curr);
	ret[len] = c;
	ret[len + 1] = '\0';
	return (ret);
}

int	closed_quotes(char *cmd)
{
	int		i;
	char	q;

	i = 0;
	q = 0;
	while (cmd[i])
	{
		if (!q && (cmd[i] == '\'' || cmd[i] == '\"'))
			q = cmd[i];
		else if (cmd[i] == q)
			q = 0;
		i++;
	}
	if (q)
	{
		ft_putstr_fd("Unclosed quotes.\n", 2);
		return (-1);
	}
	return (1);
}
