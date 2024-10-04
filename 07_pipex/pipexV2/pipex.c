/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:43:40 by hepereir          #+#    #+#             */
/*   Updated: 2024/10/04 23:49:10 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(char *argv, char **envp)
{
	char	**cmdsarr;
	char	*path;

	cmdsarr = ft_split_adapt(argv, ' ');
	ft_split_result(cmdsarr);
	path = ft_path(cmdsarr, envp);
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

int	ft_execute_child(char *argv, char **envp)
{
	int	fd[2];
	int	pid;

	ft_handle_error(pipe(fd), "Pipe Error");
	pid = ft_handle_error(fork(), "Fork error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		return (pid);
	}
	return (0);
}

static void	ft_wait(void)
{
	int	status;

	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
}

static void	ft_loop_process(int argc, char **argv, char **envp)
{
	int	pid[10000];
	int	i;
	int	wfd;

	i = 2;
	while (i < (argc - 2))
	{
		pid[i - 2] = ft_execute_child(argv[i], envp);
		i++;
	}
	wfd = ft_handle_error(open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
				0644), "Error opening file2");
	dup2(wfd, STDOUT_FILENO);
	close(wfd);
	pid[i - 2] = ft_handle_error(fork(), "Fork error");
	if (pid[i - 2] == 0)
		ft_execute(argv[argc - 2], envp);
	ft_wait();
}

int	main(int argc, char **argv, char **envp)
{
	int	rfd;
	int	wfd;

	if (argc >= 5)
	{
		rfd = ft_handle_error(open(argv[1], O_RDONLY, 0777),
				"Error opening file1");
		dup2(rfd, STDIN_FILENO);
		close(rfd);
		wfd = ft_handle_error(open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
					0644), "Error opening file2");
		close(wfd);
		ft_loop_process(argc, argv, envp);
	}
	else
		perror("Error ARGS,correct usage: ./pipex file1 cmd1 cmdn... file2");
	return (0);
}
