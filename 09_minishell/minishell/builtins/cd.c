/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:29:47 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:41:29 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BUFFER_PWD 4096

// CD BUILTINS
// Expected input args[0]=cd; args[1]=Relative or absolute path; args[2]=NULL
// Return 0 Ok; -1 Error
static char	*ft_get_cwd(int out)
{
	char	buffer[BUFFER_PWD];
	char	*pwd;

	if (getcwd(buffer, BUFFER_PWD) != NULL)
	{
		pwd = ft_strdup(buffer);
		if (!pwd)
			return (NULL);
		return (pwd);
	}
	else
	{
		ft_putstr_fd("PWD: Error\n", out);
		return (NULL);
	}
}

void	ft_change_pwd(t_envc *env, int out)
{
	t_envc	*temp;
	char	*old;

	temp = env;
	old = NULL;
	while (temp)
	{
		if (ft_strcmp(temp->var, "OLDPWD") == 0)
			if (temp->value)
				free(temp->value);
		if (ft_strcmp(temp->var, "PWD") == 0)
			old = temp->value;
		temp = temp->next;
	}
	temp = env;
	while (temp)
	{
		if (ft_strcmp(temp->var, "OLDPWD") == 0)
			temp->value = old;
		if (ft_strcmp(temp->var, "PWD") == 0)
			temp->value = ft_get_cwd(out);
		temp = temp->next;
	}
}

static int	ft_go_oldpwd(int out)
{
	t_envc	*temp;

	temp = get_shell()->env;
	while (temp)
	{
		if (ft_strcmp(temp->var, "OLDPWD") == 0 && temp->value)
		{
			if (chdir(temp->value) != 0)
			{
				ft_putstr_fd(temp->value, out);
				ft_putstr_fd(": No such file or directory\n", out);
				get_shell()->command_status = 1;
				return (-1);
			}
			ft_change_pwd(get_shell()->env, out);
			return (0);
		}
		temp = temp->next;
	}
	if (temp == NULL)
		ft_putstr_fd("cd: OLDPWD not set\n", out);
	return (-1);
}

static int	ft_cd_aux(char **args, int out)
{
	if (ft_strcmp(args[1], "-") == 0)
	{
		if (ft_go_oldpwd(out) == -1)
			return (-1);
	}
	else if (chdir(args[1]) != 0)
	{
		ft_putstr_fd(args[1], out);
		ft_putstr_fd(": No such file or directory\n", out);
		return (-1);
	}
	ft_change_pwd(get_shell()->env, out);
	return (0);
}

int	ft_cd(char **args, int out)
{
	int	i;
	int	cs;

	i = 0;
	cs = 0;
	get_shell()->command_status = 1;
	while (args[i])
		i++;
	if (i == 1 || (i == 2 && ft_strcmp(args[1], "~") == 0))
	{
		if (ft_go_home(out) == -1)
			cs = 1;
	}
	else if (i == 2)
	{
		if (ft_cd_aux(args, out) == -1)
			cs = 1;
	}
	else
	{
		ft_putstr_fd("cd: too many arguments\n", out);
		cs = 1;
	}
	get_shell()->command_status = cs;
	return (0);
}
