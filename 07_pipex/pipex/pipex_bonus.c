/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:43:40 by hepereir          #+#    #+#             */
/*   Updated: 2024/09/17 22:35:46 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute_child1(int *fd, char **argv, char **envp)
{
	int		rfd;
	char	*path;
	char	**cmdsarr;

	rfd = ft_handle_error(open(argv[1], O_RDONLY, 0777), "Error opening file1");
	dup2(rfd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(rfd);
	close(fd[0]);
	close(fd[1]);
	cmdsarr = ft_split(argv[2], ' ');
	ft_split_result(cmdsarr);
	path = ft_path(cmdsarr, envp);
	if (!path)
	{
		perror("Command not found");
		exit(1);
	}
	execve(path, cmdsarr, envp);
	perror("Error executing the cmd1");
	ft_free(cmdsarr);
	free(path);
	exit(1);
}

void	ft_execute_child2(int *fd, char **argv, char **envp)
{
	int		wfd;
	char	*path;
	char	**cmdsarr;

	wfd = ft_handle_error(open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777),
			"Error opening file2");
	dup2(wfd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(wfd);
	close(fd[0]);
	close(fd[1]);
	cmdsarr = ft_split(argv[3], ' ');
	ft_split_result(cmdsarr);
	path = ft_path(cmdsarr, envp);
	if (!path)
	{
		perror("Command not found");
		exit(1);
	}
	execve(path, cmdsarr, envp);
	perror("Error executing the cmd2");
	ft_free(cmdsarr);
	free(path);
	exit(1);
}

/* int	main(int argc, char **argv, char **envp)
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
} */

int main(int argc, char **argv, char **envp)
{
	int rfd;
	int wfd;
	int	i;
	
	i = 2;
    if (argc >= 5)
	{
		rfd = ft_handle_error(open(argv[1], O_RDONLY, 0777), "Error opening file1");
		wfd = ft_handle_error(open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777),
			"Error opening file2");
		dup2(rfd, STDIN_FILENO);
		while (i < (argc - 2))
		{
			/* execute child*/
			i++;
		}
		dup2(wfd, STDOUT_FILENO);
		//execute(argv[argc - 2], envp);
	}
	
    return 0;
}