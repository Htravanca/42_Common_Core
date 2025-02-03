/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:14:47 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:14:48 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* parse quotes adding \2
	before and after opening and closing quotes */
char	*parse_quotes(char *replaced, char **cmd)
{
	int		len;
	char	flag;
	char	*temp;
	char	*joined;

	temp = *cmd;
	flag = *temp;
	len = 1;
	while (temp[len] && temp[len] != flag)
		len++;
	temp = ft_substr(temp, 0, len + 1);
	*cmd += len + 1;
	if (!temp)
		return (NULL);
	if (replaced)
	{
		joined = ft_strjoin(replaced, temp);
		free(temp);
		free(replaced);
	}
	else
		return (temp);
	return (joined);
}
