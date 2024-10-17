/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:43:27 by hepereir          #+#    #+#             */
/*   Updated: 2024/10/17 12:08:55 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_options(void)
{
	char	**options;

	options = (char **)malloc(3 * sizeof(char *));
	if (!options)
		exit(1);
	options[0] = ft_strdup("/usr/bin");
	options[1] = ft_strdup("/bin");
	options[2] = NULL;
	return (options);
}

void	ft_wait(int i)
{
	int	status;
	int	statusf;
	int	pid_bf;
	int	pid_now;

	statusf = 0;
	pid_bf = 0;
	while ((i - 2) >= 0)
	{
		pid_now = waitpid(-1, &status, 0);
		if (WIFEXITED(status) && pid_now > pid_bf)
			statusf = WEXITSTATUS(status);
		pid_bf = pid_now;
		i--;
	}
	exit(statusf);
}

void	ft_open_files(int argc, char **argv)
{
	int	rfd;
	int	wfd;

	rfd = open(argv[1], O_RDONLY, 0777);
	wfd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (rfd == -1 || wfd == -1)
	{
		close(wfd);
		close(rfd);
		if (rfd == -1)
		{
			perror("Error opening infile");
			exit(1);
		}
		if (wfd == -1)
		{
			perror("Error opening outfile");
			exit(1);
		}
	}
	dup2(rfd, STDIN_FILENO);
	close(rfd);
	close(wfd);
}

void	ft_split_result(char **cmdsarr)
{
	if (!cmdsarr || !cmdsarr[0])
	{
		ft_free_arr(cmdsarr);
		perror("Command not found");
		exit(127);
	}
}
