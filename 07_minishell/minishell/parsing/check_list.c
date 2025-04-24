/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:14:54 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:15:27 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_idx(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tokens[i])
	{
		if (tokens[i][0])
			j++;
		i++;
	}
	return (j);
}

static char	**remove_empty_idx(char **tokens)
{
	int		i;
	int		j;
	char	**new;
	int		count;

	i = -1;
	j = 0;
	count = count_idx(tokens);
	new = ft_calloc(sizeof(char *), count + 1);
	if (!new)
		ft_free();
	while (tokens[++i])
	{
		if (!tokens[i][0])
		{
			free(tokens[i]);
			continue ;
		}
		else
			new[j++] = tokens[i];
	}
	free(tokens);
	new[j] = 0;
	return (new);
}

void	check_list(void)
{
	int			i;
	t_tokens	*tokens;

	tokens = get_shell()->tokens;
	while (tokens)
	{
		i = 0;
		while (tokens->token && tokens->token[i])
		{
			if (!tokens->token[i][0])
			{
				tokens->token = remove_empty_idx(tokens->token);
				continue ;
			}
			i++;
		}
		tokens = tokens->next;
	}
}
