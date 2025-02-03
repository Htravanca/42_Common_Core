/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:00:52 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/30 17:17:00 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// close all the files in the next comands
void	ft_close_rest(t_tokens *tokens)
{
	tokens = tokens->next;
	while (tokens)
	{
		ft_close(tokens->io.fd_in);
		ft_close(tokens->io.fd_out);
		if (tokens->here_doc)
			ft_close(tokens->heredoc_fd[0]);
		tokens = tokens->next;
	}
}

// Close file descriptor safely
void	ft_close(int fd)
{
	if (fd > 2)
		close(fd);
}

// function to handle error of pipe and fork
int	ft_handle_error(int val, const char *msg, int ret_val)
{
	if (val < 0)
	{
		perror(msg);
		ft_free_bf_exit();
		exit(ret_val);
	}
	return (val);
}

// in case of the path is not found it displays error
void	print_path_error(char *s)
{
	char	*result;

	result = ft_strjoin(s, ": command not found\n");
	write(2, result, ft_strlen(result));
	free (result);
}
