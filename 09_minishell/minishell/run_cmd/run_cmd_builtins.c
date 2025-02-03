/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:49:38 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/17 19:26:12 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// close saved stdin and stdout
void	ft_close_savedstd(t_tokens *tokens, int in, int out)
{
	ft_close(in);
	ft_close(out);
	if (tokens->io.saved_stdin > 2)
		close(tokens->io.saved_stdin);
	if (tokens->io.saved_stdout > 2)
		close(tokens->io.saved_stdout);
}

// calls the builtins
static void	execute_builtin(t_tokens *tokens, int in, int out)
{
	if (tokens->is_builtin == 1)
		ft_echo(tokens->token, out);
	else if (tokens->is_builtin == 2)
		ft_cd(tokens->token, out);
	else if (tokens->is_builtin == 3)
		ft_pwd(out);
	else if (tokens->is_builtin == 4)
		ft_export(tokens->token, &get_shell()->env, out);
	else if (tokens->is_builtin == 5)
		ft_unset(tokens->token, &get_shell()->env);
	else if (tokens->is_builtin == 7)
		ft_env(get_shell()->env, out);
	else if (tokens->is_builtin == 6)
		ft_exit(tokens, in, out);
}

// check if the comand is a built in and executes it
int	check_builtins(t_tokens *tokens, int in, int out)
{
	if (get_shell()->tokens->next)
		tokens->pid = ft_handle_error(fork(), "Fork error", 1);
	else
	{
		tokens->io.saved_stdin = dup(STDIN_FILENO);
		tokens->io.saved_stdout = dup(STDOUT_FILENO);
	}
	if (!tokens->pid)
	{
		ft_redirect(in, out);
		execute_builtin(tokens, in, out);
		if (get_shell()->tokens->next)
		{
			ft_close_error(in, out, tokens);
			ft_close_rest(tokens);
			ft_free_bf_exit();
			exit(get_shell()->command_status);
		}
	}
	dup2(tokens->io.saved_stdin, STDIN_FILENO);
	dup2(tokens->io.saved_stdout, STDOUT_FILENO);
	ft_close_savedstd(tokens, in, out);
	return (1);
}
