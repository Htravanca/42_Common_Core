/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:43:40 by hepereir          #+#    #+#             */
/*   Updated: 2024/09/19 17:55:15 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_execute(char *argv, char **envp)
{
	char **cmdsarr;
	char *path;
	
	cmdsarr = ft_split(argv, ' ');
	ft_split_result(cmdsarr);
	path = ft_path(cmdsarr, envp);
	if (!path)
	{
		perror("Command not found");
		ft_free(cmdsarr);
		exit(1);
	}
	execve(path, cmdsarr, envp);
	perror("Error executing the cmd");
	ft_free(cmdsarr);
	free(path);
	exit(1);
}

int	ft_handle_error(int val, const char *msg)
{
	if (val < 0)
	{
		perror(msg);
		exit(1);
	}
	return (val);
}

void	ft_execute_child(char *argv, char **envp)
{
	int	fd[2];
	int	pid;

	ft_handle_error(pipe(fd), "Pipe Error");
	pid = ft_handle_error(fork(), "Fork error");
	if(pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

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
			ft_execute_child(argv[i], envp);
			i++;
		}
		dup2(wfd, STDOUT_FILENO);
		ft_execute(argv[argc - 2], envp);
	}
	else
		perror("Error in ARGS, correct usage: ./pipex file1 cmd1 cmd2 cmdn... file2");
    return 0;
}
