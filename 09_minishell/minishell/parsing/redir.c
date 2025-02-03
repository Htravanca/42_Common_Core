/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:37:14 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:13:36 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	populate_redir(char **arr, t_tokens *lsttokens, int type)
{
	t_redir	*curr;

	curr = lst_redir();
	if (!curr)
	{
		ft_free_err(arr, "Error creating redir node.");
		if (lsttokens->redir)
			free_redir(&lsttokens->redir);
		free_lst();
		exit(1);
	}
	curr->filename = arr[1];
	free(arr[0]);
	arr[0] = NULL;
	curr->type = type;
	if (!lsttokens->redir)
		lsttokens->redir = curr;
	else
		ft_lstadd_back_redir(&lsttokens->redir, curr);
}

static int	get_redir_len(char *tok)
{
	if (tok[0] == '<' || tok[0] == '>')
	{
		if (tok[0] == '>' && tok[1] == '>')
			return (2);
		else if (tok[0] == '<' && tok[1] == '<')
			return (2);
		else if (tok[0] == '>')
			return (1);
		else if (tok[0] == '<')
			return (1);
		return (0);
	}
	return (0);
}

char	*parse_redir(char *replaced, char **cmd)
{
	int		i;
	char	*redir;
	char	*temp;

	i = get_redir_len(*cmd);
	redir = ft_substr(*cmd, 0, i);
	if (!redir)
		return (NULL);
	temp = ft_strjoin("\2", redir);
	*cmd += i;
	free(redir);
	if (!temp)
		return (NULL);
	redir = ft_strjoin(temp, "\2");
	free(temp);
	if (!redir)
		return (NULL);
	if (replaced)
	{
		temp = ft_strjoin(replaced, redir);
		free(replaced);
		free(redir);
		return (temp);
	}
	return (redir);
}

int	get_type(char *tok)
{
	if (tok[0] == '<' || tok[0] == '>')
	{
		if (!ft_strcmp(tok, "<<"))
			return (5);
		else if (!ft_strcmp(tok, ">>"))
			return (4);
		else if (!ft_strcmp(tok, ">"))
			return (3);
		else if (!ft_strcmp(tok, "<"))
			return (2);
	}
	return (0);
}
