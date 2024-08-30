#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

// PIPEX
void	ft_execute_child1(int *fd, char **argv, char **envp);
void	ft_execute_child2(int *fd, char **argv, char **envp);

// PIPEX AUX
char	*ft_path(char *cmd, char **envp);
void	ft_free(char **var);

#endif