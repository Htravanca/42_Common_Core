/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:00:52 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/30 17:13:43 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// setup with dup2 the redirections opened bf
void	ft_redirect(int in, int out)
{
	if (in != STDIN_FILENO)
		dup2(in, STDIN_FILENO);
	if (out != STDOUT_FILENO)
		dup2(out, STDOUT_FILENO);
}

// calls the funcitons needed bf exit, to dont have leaks
void	ft_free_bf_exit(void)
{
	ft_free_arr(get_shell()->env_arr);
	free_redir(&get_shell()->tokens->redir);
	free_lst();
	ft_lstclear_env(&get_shell()->env);
}

// close both ends of the current pipe
static void	ft_close_pipe(t_tokens *tokens)
{
	ft_close(tokens->fd[0]);
	ft_close(tokens->fd[1]);
}

// close the thing open bf exit on error
void	ft_close_error(int in, int out, t_tokens *tokens)
{
	ft_close(in);
	ft_close(out);
	ft_close_pipe(tokens);
}

// funtion to execute the comand with execve
void	ft_execute(t_tokens *tokens, int in, int out)
{
	char	*path;

	tokens->pid = ft_handle_error(fork(), "Fork error", 1);
	if (!tokens->pid)
	{
		handle_sig(CHILD);
		ft_redirect(in, out);
		if (tokens->next)
			ft_close_pipe(tokens);
		path = ft_path(tokens->token, get_shell()->env_arr, tokens->token[0]);
		if (!path)
			print_path_error(tokens->token[0]);
		else
			execve(path, tokens->token, get_shell()->env_arr);
		ft_close_error(in, out, tokens);
		ft_close_rest(tokens);
		ft_free_bf_exit();
		exit(127);
	}
	ft_close(in);
	ft_close(out);
}
