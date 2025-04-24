/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:08:19 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/30 16:19:34 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// signals in normal mode
static void	handle_sigint(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// signals in heredoc mode
static void	handle_sigint_heredoc(int signal)
{
	(void)signal;
	signal_status = SIGINT;
}

// signals in parent process waiting for child to finish
static void	handle_sigint_parent(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n", 1);
}

void	handle_sig(t_sigs mode)
{
	if (mode == PARENT)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == CHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (mode == HEREDOC)
	{
		signal(SIGINT, handle_sigint_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == PARENT_WAIT)
	{
		signal(SIGINT, handle_sigint_parent);
		signal(SIGQUIT, SIG_IGN);
	}
}
