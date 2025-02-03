/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:26:21 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/29 20:42:07 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// print the file in wich there is an error
static void	ft_print_error(t_tokens *tokens)
{
	t_redir	*current;

	current = tokens->redir;
	if (tokens->io.fd_out == -1 || tokens->io.fd_in == -1)
	{
		while (current)
		{
			if (current->type == ERROR)
			{
				open(current->filename, O_RDONLY);
				perror(current->filename);
				break ;
			}
			current = current->next;
		}
	}
}

// function to handle in case of error in infile or outfile
void	ft_handle_errorfiles(t_tokens *tokens, int in, int out)
{
	tokens->pid = ft_handle_error(fork(), "Fork error", 1);
	if (!tokens->pid)
	{
		ft_close_error(in, out, tokens);
		ft_close_rest(tokens);
		ft_free_bf_exit();
		exit(1);
	}
	ft_print_error(tokens);
	ft_close(in);
	ft_close(out);
}

// function to close fd_in and fd_out
void	ft_close_redir(t_tokens *tokens)
{
	if (tokens->io.fd_in != STDIN_FILENO)
		close(tokens->io.fd_in);
	if (tokens->io.fd_out != STDOUT_FILENO)
		close(tokens->io.fd_out);
}

// function to check if there is any error in files and prints error
int	ft_file_error(t_tokens *tokens, int in, int out)
{
	t_redir	*current;
	int		rt;

	rt = 0;
	current = tokens->redir;
	while (current)
	{
		if (current->type == ERROR)
		{
			ft_handle_errorfiles(tokens, in, out);
			rt = 1;
			break ;
		}
		current = current->next;
	}
	return (rt);
}
