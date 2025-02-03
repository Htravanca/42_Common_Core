/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_wait.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:47:58 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/31 13:14:22 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//function to handle the child process ending in CRTL+slash
void	wait_all_aux(int status)
{
	int	signal;

	signal = WTERMSIG(status);
	if (signal == SIGQUIT)
		write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
	get_shell()->command_status = 128 + signal;
}

// Wait for all child processes to finish
void	wait_all(t_tokens *current)
{
	int	status;
	//int	pid_bf;
	int	pid_now;

	//pid_bf = 0;
	status = 0;
	while (current)
	{
		if (current->pid != 0)
		{
			pid_now = waitpid(-1, &status, 0);
			if (pid_now > 0)
			{
				if (WIFEXITED(status))
					get_shell()->command_status = WEXITSTATUS(status);
				else if (WIFSIGNALED(status))
					wait_all_aux(status);
			}
			//pid_bf = pid_now;
		}
		current = current->next;
	}
}
