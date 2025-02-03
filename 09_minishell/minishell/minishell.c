/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:29:29 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:46:33 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	signal_status;

static void	init_env(char **env)
{
	get_shell()->env = NULL;
	get_shell()->env = ft_env_cpy(env, get_shell()->env);
	get_shell()->env_arr = ft_convert_array(get_shell()->env);
}

static void	final_exit(void)
{
	ft_putstr_fd("exit\n", 1);
	ft_free_arr(get_shell()->env_arr);
	ft_lstclear_env(&get_shell()->env);
	free_redir(&get_shell()->tokens->redir);
	free_lst();
	rl_clear_history();
}

int	main(int argc, char **argv, char **env)
{
	char	*cmd;

	init_env(env);
	while (true)
	{
		handle_sig(PARENT);
		cmd = readline("> ");
		if (!cmd)
			break ;
		if (*cmd != '\0')
		{
			add_history(cmd);
			if (check_syntax(cmd))
			{
				parse_input(cmd);
				ft_runcmd();
				free_lst();
				get_shell()->tokens = NULL;
			}
		}
		free(cmd);
	}
	final_exit();
	return ((void)argc, (void)argv, 0);
}
