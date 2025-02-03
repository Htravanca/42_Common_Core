/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:36:13 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/17 11:12:36 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// join to the current node all possible path and try to acess it
static char	*ft_find_path(char **options, char *cmd)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	*pfinal;

	i = 0;
	pfinal = NULL;
	while (options[i])
	{
		temp = ft_strjoin(options[i], "/");
		temp2 = ft_strjoin(temp, cmd);
		free(temp);
		if (access(temp2, F_OK) == 0)
		{
			pfinal = ft_strdup(temp2);
			free(temp2);
			break ;
		}
		free(temp2);
		i++;
	}
	return (pfinal);
}

// check if the current token is an abslute path
static int	ft_check_path(char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}

// looks for the path in the current env
char	*ft_path(char **cmdsarr, char **envp, char *path)
{
	char	**options;
	char	*pfinal;
	int		i;

	i = 0;
	pfinal = NULL;
	options = NULL;
	if (ft_check_path(path))
		return (path);
	while (envp && envp[i] && !ft_strnstr(envp[i], "PATH", 4))
		i++;
	if (envp[i])
	{
		options = ft_split(envp[i] + 5, ':');
		if (!options)
			return (NULL);
	}
	if (options != NULL && options[0] != NULL)
	{
		pfinal = ft_find_path(options, cmdsarr[0]);
		ft_free_arr(options);
	}
	return (pfinal);
}
