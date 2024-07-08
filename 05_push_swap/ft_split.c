/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:07:23 by hepereir          #+#    #+#             */
/*   Updated: 2024/06/22 19:12:40 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			j++;
	}
	return (count);
}

static char	*ft_aux_write(char *arr, char *pos_begin, size_t len)
{
	size_t	j;

	j = 0;
	while (j < len)
	{
		arr[j] = pos_begin[j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

static char	*ft_write_arr(char const *s, char c, size_t *pos)
{
	char	*pos_begin;
	char	*pos_final;
	size_t	len;
	char	*arr;

	len = 0;
	pos_begin = (char *)&s[*pos];
	while (s[*pos] == c && s[*pos])
	{
		pos_begin = (char *)&s[*pos + 1];
		(*pos)++;
	}
	pos_final = (char *)&s[*pos];
	while (s[*pos] != c && s[*pos])
	{
		pos_final = (char *)&s[*pos + 1];
		(*pos)++;
	}
	len = pos_final - pos_begin;
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	arr = ft_aux_write(arr, pos_begin, len);
	return (arr);
}

void	ft_free(char **arr, size_t atual)
{
	while (atual > 0)
	{
		free(arr[atual - 1]);
		atual--;
	}
	free (arr);
}

char	**ft_split(char const *s, char c)
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
