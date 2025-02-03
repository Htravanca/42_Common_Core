/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:18:03 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/03 21:18:06 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_delimiters(char const *s, char c)
{
	int	delimiters;
	int	i;

	delimiters = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			delimiters++;
			while (s[i] && s[i] != c)
				i++;
			if (s[i] == '\0')
				return (delimiters);
		}
		i++;
	}
	return (delimiters);
}

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**populate_array(char const *s, char c, char **arr,
		int delimiters_num)
{
	int	i;
	int	j;

	i = 0;
	while (*s && i < delimiters_num)
	{
		while (*s == c && *s)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		arr[i] = ft_calloc(j + 1, sizeof(char));
		if (!arr[i])
			return (ft_free(arr), NULL);
		j = 0;
		while (*s != c && *s)
		{
			arr[i][j++] = *s;
			s++;
		}
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**final_arr;
	int		delimiters_num;

	if (!s)
		return (NULL);
	delimiters_num = count_delimiters(s, c);
	final_arr = malloc(sizeof(char *) * (delimiters_num + 1));
	if (!final_arr)
		return (NULL);
	populate_array(s, c, final_arr, delimiters_num);
	return (final_arr);
}
