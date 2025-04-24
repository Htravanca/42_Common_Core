/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:54:42 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:10:48 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strdup_q(char *token)
{
	int		i;
	int		j;
	char	*new;
	char	q;

	i = 0;
	j = 0;
	q = 0;
	new = ft_calloc(sizeof(char), ft_strlen(token) + 1);
	if (!new)
		return (NULL);
	while (token && token[i])
	{
		if ((token[i] == '\'' || token[i] == '\"') && !q)
			q = token[i++];
		else if (token[i] == q)
		{
			q = 0;
			i++;
		}
		else
			new[j++] = token[i++];
	}
	free(token);
	return (new);
}

void	check_quotes_tokens(void)
{
	int			i;
	t_tokens	*tokens;
	char		*new;

	tokens = get_shell()->tokens;
	while (tokens)
	{
		i = -1;
		while (tokens->token && tokens->token[++i])
		{
			new = ft_strdup_q(tokens->token[i]);
			if (!new)
				ft_free();
			tokens->token[i] = new;
			check_quotes_redir(tokens);
		}
		tokens = tokens->next;
	}
}

void	check_quotes_redir(t_tokens *tokens)
{
	t_redir	*redir;
	char	*new;

	redir = tokens->redir;
	while (redir)
	{
		new = ft_strdup_q(redir->filename);
		if (!new)
			ft_free();
		redir->filename = new;
		redir = redir->next;
	}
}
