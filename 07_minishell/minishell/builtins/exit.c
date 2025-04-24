/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:36:19 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:41:36 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_finish(t_tokens *tokens, int in, int out)
{
	ft_close_savedstd(tokens, in, out);
	ft_close(tokens->fd[0]);
	ft_close(tokens->fd[1]);
	ft_free_bf_exit();
}

static int	count_args(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static int	ft_isallnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (!(i == 0 && (str[i] == '-' || str[i] == '+')))
				return (0);
		}
		i++;
	}
	return (1);
}

static void	ft_exit2(t_tokens *tokens, int in, int out)
{
	ft_putstr_fd("exit\n", out);
	if (ft_isallnum(tokens->token[1]))
	{
		ft_putstr_fd("exit: Too many arguments\n", out);
		get_shell()->command_status = 1;
		return ;
	}
	else
	{
		ft_putstr_fd("exit: ", out);
		ft_putstr_fd(tokens->token[1], out);
		ft_putstr_fd(": numeric argument required\n", out);
		ft_finish(tokens, in, out);
		exit(2);
	}
}

void	ft_exit(t_tokens *tokens, int in, int out)
{
	int	exit_code;

	if (!tokens->token[1])
	{
		ft_putstr_fd("exit\n", out);
		ft_finish(tokens, in, out);
		exit(0);
	}
	exit_code = ft_atoi(tokens->token[1]);
	if (exit_code < 0)
		exit_code = 256 + (exit_code % 256);
	if (count_args(tokens->token) > 2)
		ft_exit2(tokens, in, out);
	else if (tokens->token[1] && ft_isallnum(tokens->token[1]))
	{
		ft_putstr_fd("exit\n", out);
		ft_finish(tokens, in, out);
		exit(exit_code);
	}
	else
		ft_exit3(tokens, in, out);
}
