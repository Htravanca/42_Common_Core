/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_heredoc2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:51:39 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/27 20:53:11 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ft to close the pipe created to heredoc
void	ft_close_herepipe(int heredoc[2])
{
	ft_close(heredoc[1]);
	ft_close(heredoc[0]);
}

// ft to go though all tokens and close all heredoc pipes
void	ft_close_allpipes(t_tokens *tokens)
{
	while (tokens)
	{
		ft_close_herepipe(tokens->heredoc_fd);
		tokens = tokens->next;
	}
}
