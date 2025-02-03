/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:36:19 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/27 21:00:35 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Function to handle a simple comand
static void	handle_execute(t_tokens *tokens, int in, int out)
{
	if (ft_file_error(tokens, in, out) == 1)
		return ;
	if (tokens->is_builtin != 0)
	{
		check_builtins(tokens, in, out);
		return ;
	}
	if (tokens->token[0])
	{
		ft_execute(tokens, in, out);
	}
	else
	{
		ft_close(in);
		ft_close(out);
	}
}

// funtiom to open the pipe and close prev out and change to new one
static void	ft_pipe(int *out, t_tokens *current)
{
	pipe(current->fd);
	ft_close(*out);
	*out = current->fd[1];
}

// function to handle fds and change to new one
static void	ft_change_fd(int *in, int *out, t_tokens *current)
{
	if (current->io.fd_in)
	{
		ft_close(*in);
		*in = current->io.fd_in;
	}
	if (current->io.fd_out)
	{
		ft_close(*out);
		*out = current->io.fd_out;
	}
	if (current->here_doc)
	{
		ft_close(*in);
		*in = current->heredoc_fd[0];
	}
}

// Function to iterate though the tokenss
void	ft_runcmd(void)
{
	t_tokens	*current;
	int			in;
	int			out;

	in = 0;
	out = 1;
	current = get_shell()->tokens;
	if (ft_setup_redir(current) == -1)
		return ;
	handle_sig(PARENT_WAIT);
	while (current)
	{
		out = 1;
		if (current->next)
			ft_pipe(&out, current);
		ft_change_fd(&in, &out, current);
		handle_execute(current, in, out);
		if (current->next)
			in = current->fd[0];
		current = current->next;
	}
	ft_close(in);
	ft_close(out);
	wait_all(get_shell()->tokens);
}
