/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:43:27 by hepereir          #+#    #+#             */
/*   Updated: 2024/10/06 14:50:09 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_options(void)
{
	char	**options;

	options = (char **)malloc(3 * sizeof(char *));
	if (!options)
		exit(1);
	options[0] = ft_strdup("/usr/bin");
	options[1] = ft_strdup("/bin");
	options[2] = NULL;
	return (options);
}

void	ft_wait(int i)
{
	int	status;
	int	statusf;
	int	exit_status;

	statusf = 0;
	while ((i - 2) >= 0)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0 && exit_status != 1)
				statusf = exit_status;
		}
		i--;
	}
	exit(statusf);
}
