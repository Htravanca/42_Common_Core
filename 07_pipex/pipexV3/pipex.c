/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:43:40 by hepereir          #+#    #+#             */
/*   Updated: 2024/10/11 18:27:32 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_execute(char *argv, char **envp)
{
	char	**cmdsarr;
	char	*path;

	cmdsarr = ft_split_adapt(argv, ' ');
	ft_split_result(cmdsarr);
	path = ft_path(cmdsarr, envp, argv);
	if (!path)
	{
		perror("Command not found");
		ft_free_arr(cmdsarr);
		exit(127);
	}
	execve(path, cmdsarr, envp);
	perror("Error executing the cmd");
	ft_free_arr(cmdsarr);
	free(path);
	exit(1);
}

static void	ft_execute_child(char *argv, char **envp, int *fd, int *prev_fd)
{
	int	pid;

	pid = ft_handle_error(fork(), "Fork error", 1);
	if (pid == 0)
	{
		if (*prev_fd != -1)
		{
			dup2(*prev_fd, STDIN_FILENO);
			close(*prev_fd);
		}
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_execute(argv, envp);
	}
	close(fd[1]);
	if (*prev_fd != -1)
		close(*prev_fd);
	*prev_fd = fd[0];
}

static void	ft_execute_last(int wfd, int prev_fd)
{
	dup2(prev_fd, STDIN_FILENO);
	close(prev_fd);
	dup2(wfd, STDOUT_FILENO);
	close(wfd);
}

static void	ft_loop_process(int argc, char **argv, char **envp)
{
	int	pid;
	int	i;
	int	prev_fd;
	int	fd[2];
	int	wfd;

	i = 2;
	prev_fd = -1;
	while (i < (argc - 2))
	{
		ft_handle_error(pipe(fd), "Pipe Error", 1);
		ft_execute_child(argv[i], envp, fd, &prev_fd);
		i++;
	}
	wfd = ft_handle_error(open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
				0644), "Error opening outfile", 1);
	pid = ft_handle_error(fork(), "Fork error", 1);
	if (pid == 0)
	{
		ft_execute_last(wfd, prev_fd);
		ft_execute(argv[argc - 2], envp);
	}
	close(prev_fd);
	close(wfd);
	ft_wait(i);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
	{
		ft_open_files(argc, argv);
		ft_loop_process(argc, argv, envp);
	}
	else
		perror("Error ARGS,correct usage: ./pipex file1 cmd1 cmdn... file2");
	return (0);
}
