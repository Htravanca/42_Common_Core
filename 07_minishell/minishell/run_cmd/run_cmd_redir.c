/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:34:13 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/26 22:04:34 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// open the append outfile
static void	ft_redir_out_appnd(t_tokens *tokens, t_redir *current)
{
	ft_close(tokens->io.fd_out);
	tokens->io.fd_out = open(current->filename, O_WRONLY | O_CREAT | O_APPEND,
			0644);
}

// open the outfiles
static void	ft_redir_out(t_tokens *tokens, t_redir *current)
{
	ft_close(tokens->io.fd_out);
	tokens->io.fd_out = open(current->filename, O_WRONLY | O_CREAT | O_TRUNC,
			0644);
}

// open the infiles
static void	ft_redir_in(t_tokens *tokens, t_redir *current)
{
	ft_close(tokens->io.fd_in);
	tokens->io.fd_in = open(current->filename, O_RDONLY);
}

// looks if in the current tokens there is at least one here_doc
static int	ft_current_doc(t_tokens *tokens)
{
	t_redir		*current;
	t_tokens	*temp;

	temp = tokens;
	while (temp)
	{
		current = temp->redir;
		while (current)
		{
			if (current->type == HERE_DOC)
				temp->here_doc = 1;
			current = current->next;
		}
		if (temp->here_doc == 1)
			ft_here_doc(temp);
		if (signal_status == SIGINT)
		{
			ft_close_allpipes(tokens);
			signal_status = 0;
			return (-1);
		}
		temp = temp->next;
	}
	return (0);
}

// Goes though all the tokens nodes and open the rediretions
int	ft_setup_redir(t_tokens *tokens)
{
	t_redir	*current;

	if (ft_current_doc(tokens) == -1)
		return (-1);
	while (tokens)
	{
		current = tokens->redir;
		while (current)
		{
			if (current->type == REDIR_IN)
				ft_redir_in(tokens, current);
			else if (current->type == REDIR_OUT)
				ft_redir_out(tokens, current);
			else if (current->type == REDIR_OUT_APPND)
				ft_redir_out_appnd(tokens, current);
			if (tokens->io.fd_out == -1 || tokens->io.fd_in == -1)
			{
				current->type = ERROR;
				break ;
			}
			current = current->next;
		}
		tokens = tokens->next;
	}
	return (0);
}
