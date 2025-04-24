/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:32:53 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:17:03 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*ft_lsttoken(char **args)
{
	t_tokens	*lsttokens;

	lsttokens = ft_calloc(1, sizeof(t_tokens));
	if (!lsttokens)
		return (NULL);
	lsttokens->token = args;
	if (!lsttokens->token)
		return (NULL);
	lsttokens->type = 0;
	lsttokens->io.fd_in = 0;
	lsttokens->io.fd_out = 0;
	lsttokens->redir = NULL;
	lsttokens->next = NULL;
	return (lsttokens);
}

t_tokens	*ft_tokenslast(t_tokens *tokens)
{
	if (tokens)
	{
		while (tokens->next != NULL)
			tokens = tokens->next;
	}
	return (tokens);
}

void	ft_tokensadd_front(t_tokens **tokens, t_tokens *node)
{
	node->next = *tokens;
	*tokens = node;
}

void	ft_tokensadd_back(t_tokens **token, t_tokens *node)
{
	if (*token)
		ft_tokenslast(*token)->next = node;
	else
		*token = node;
}

t_shell	*get_shell(void)
{
	static t_shell	shell;

	return (&shell);
}
