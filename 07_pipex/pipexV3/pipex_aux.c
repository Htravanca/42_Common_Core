/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:43:47 by hepereir          #+#    #+#             */
/*   Updated: 2024/10/17 11:32:56 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_arr(char **var)
{
	int	i;

	i = 0;
	if (!var)
		return ;
	while (var[i] != NULL)
	{
		free(var[i]);
		i++;
	}
	free(var);
}

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

int	ft_check_path(char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}

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
	if (i == 0)
		options = ft_options();
	else if (envp[i] && ft_strnstr(envp[i], "/usr/bin", ft_strlen(envp[i])))
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

int	ft_handle_error(int val, const char *msg, int ret_val)
{
	if (val < 0)
	{
		perror(msg);
		exit(ret_val);
	}
	return (val);
}
