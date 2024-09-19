/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:43:52 by hepereir          #+#    #+#             */
/*   Updated: 2024/09/19 18:33:52 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	ft_free(char **var);
// static char	*ft_find_path(char **options, char *cmd);
char	*ft_path(char **cmdsarr, char **envp);
int		ft_handle_error(int val, const char *msg);
void	ft_split_result(char **cmdsarr);

// PIPEX BONUS
void	ft_execute(char *argv, char **envp);
int		ft_handle_error(int val, const char *msg);
void	ft_execute_child(char *argv, char **envp);

// PIPEX BONUS AUX
void	ft_free(char **var);
// static char	*ft_find_path(char **options, char *cmd);
char	*ft_path(char **cmdsarr, char **envp);
void	ft_split_result(char **cmdsarr);

#endif