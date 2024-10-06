/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_adapt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:32:19 by hepereir          #+#    #+#             */
/*   Updated: 2024/09/22 14:33:57 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_skip_quotes(const char *s, size_t j)
{
	j++;
	while (s[j] != '\'' && s[j])
		j++;
	if (s[j] == '\'')
		j++;
	return (j);
}

static size_t	ft_count_string(char const *s, char c)
{
	size_t	j;
	size_t	count;

	count = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c && s[j])
			j++;
		if (s[j])
			count++;
		while (s[j] != c && s[j])
		{
			if (s[j] == '\'' && s[j])
				j = ft_skip_quotes(s, j);
			else
				j++;
		}
	}
	return (count);
}

static void	ft_free(char **arr, size_t atual)
{
	while (atual > 0)
	{
		free(arr[atual - 1]);
		atual--;
	}
	free(arr);
}

char	**ft_split_adapt(char const *s, char c)
{
	size_t	count;
	char	**arr;
	size_t	atual;
	size_t	pos;

	if (!s)
		return (NULL);
	pos = 0;
	atual = 0;
	count = ft_count_string(s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (atual < count)
	{
		arr[atual] = ft_write_arr(s, c, &pos);
		if (!arr[atual])
		{
			ft_free(arr, atual);
			return (NULL);
		}
		atual++;
	}
	arr[atual] = NULL;
	return (arr);
}
