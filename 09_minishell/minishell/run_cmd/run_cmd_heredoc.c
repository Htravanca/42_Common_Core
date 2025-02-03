/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:48:42 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/27 21:00:18 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// search for the first terminator in different whiles
static char	*ft_search_terminator(t_tokens *current)
{
	t_redir	*temp;
	char	*term;

	temp = current->redir;
	term = NULL;
	while (temp)
	{
		if (temp->type == HERE_DOC)
		{
			term = ft_strdup(temp->filename);
			temp->type = HERE_DOC_DONE;
			break ;
		}
		temp = temp->next;
	}
	return (term);
}

// search if there are more here_doc
static int	ft_is_heredoc(t_tokens *current)
{
	t_redir	*temp;
	int		rt;

	rt = 0;
	temp = current->redir;
	while (temp)
	{
		if (temp->type == HERE_DOC)
			rt = 1;
		temp = temp->next;
	}
	return (rt);
}

//hook to check for an sigint signal
static int	check_signal_status(void)
{
	if (signal_status == SIGINT)
		rl_done = 1;
	return (0);
}

// function to execute the logic of one hererdoc
static void	ft_execute_heredoc(t_tokens *current, int fd_out)
{
	char	*line;
	char	*terminator;

	terminator = ft_search_terminator(current);
	while (1)
	{
		signal_status = 0;
		rl_event_hook = check_signal_status;
		line = readline("heredoc> ");
		if (signal_status == SIGINT)
			break ;
		if (!line)
		{
			ft_putstr_fd("Warning: here-document ended with EOF\n", 2);
			break ;
		}
		if (ft_strcmp(line, terminator) == 0)
			break ;
		ft_putstr_fd(line, fd_out);
		ft_putstr_fd("\n", fd_out);
		free(line);
	}
	if (line != 0)
		free(line);
	free(terminator);
}

// core logic to handle heredoc
void	ft_here_doc(t_tokens *current)
{
	int	i;

	i = -1;
	signal_status = 0;
	handle_sig(HEREDOC);
	while (ft_is_heredoc(current))
	{
		if (i != -1)
			ft_close_herepipe(current->heredoc_fd);
		i = pipe(current->heredoc_fd);
		if (i == -1)
			return ;
		ft_execute_heredoc(current, current->heredoc_fd[1]);
		if (signal_status == SIGINT)
			break ;
	}
	ft_close(current->heredoc_fd[1]);
	return ;
}
