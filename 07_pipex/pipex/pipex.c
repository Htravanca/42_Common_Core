/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:43:40 by hepereir          #+#    #+#             */
/*   Updated: 2024/10/02 21:51:41 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute_child1(int *fd, char **argv, char **envp)
{
	pid_t	rfd;
	char	*path;
	char	**cmdsarr;

	rfd = ft_handle_error(open(argv[1], O_RDONLY, 0777), "Error opening file1");
	dup2(rfd, STDIN_FILENO);
	close(rfd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	cmdsarr = ft_split_adapt(argv[2], ' ');
	ft_split_result(cmdsarr);
	path = ft_path(cmdsarr, envp);
	if (!path)
	{
		perror("Command not found");
		ft_free_arr(cmdsarr);
		exit(127);
	}
	execve(path, cmdsarr, envp);
	perror("Error executing the cmd1");
	ft_free_arr(cmdsarr);
	free(path);
	exit(1);
}

void	ft_execute_child2(int *fd, char **argv, char **envp)
{
	pid_t	wfd;
	char	*path;
	char	**cmdsarr;

	wfd = ft_handle_error(open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644),
			"Error opening file2");
	dup2(wfd, STDOUT_FILENO);
	close(wfd);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	cmdsarr = ft_split_adapt(argv[3], ' ');
	ft_split_result(cmdsarr);
	path = ft_path(cmdsarr, envp);
	if (!path)
	{
		perror("Command not found");
		ft_free_arr(cmdsarr);
		exit(127);
	}
	execve(path, cmdsarr, envp);
	perror("Error executing the cmd2");
	ft_free_arr(cmdsarr);
	free(path);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc == 5)
	{
		ft_handle_error(pipe(fd), "Pipe error");
		pid1 = ft_handle_error(fork(), "Fork error");
		if (pid1 == 0)
			ft_execute_child1(fd, argv, envp);
		pid2 = ft_handle_error(fork(), "Fork error");
		if (pid2 == 0)
			ft_execute_child2(fd, argv, envp);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		perror("Error in ARGS, correct usage: ./pipex file1 cmd1 cmd2 file2");
	return (0);
}
