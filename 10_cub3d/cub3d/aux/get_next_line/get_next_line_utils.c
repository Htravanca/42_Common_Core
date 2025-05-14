/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:58:52 by hepereir          #+#    #+#             */
/*   Updated: 2025/04/12 01:29:23 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_newline(const char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

void	ft_trim(char *buffer, char *stash, int flag)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	if (flag == 1)
	{
		while (stash && stash[i])
		{
			if (stash[i] == '\n')
			{
				stash[i + 1] = '\0';
				break ;
			}
			i++;
		}
		i = 0;
		while (buffer[pos] && buffer[pos] != '\n')
			pos++;
		while (buffer[pos + 1])
			buffer[i++] = buffer[pos++ + 1];
	}
	while (buffer[i])
		buffer[i++] = '\0';
}

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s && s[j])
		j++;
	return (j);
}

char	*ft_aux(char *stash, char *buffer, int read_bytes)
{
	if (read_bytes > 0)
		stash = ft_strjoin_gnl(stash, buffer);
	if (read_bytes < 0)
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	return (stash);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	j = 0;
	i = 0;
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1 && s1[j])
	{
		result[j] = s1[j];
		j++;
	}
	while (s2 && s2[i])
	{
		result[i + j] = s2[i];
		i++;
	}
	result[j + i] = '\0';
	free(s1);
	return (result);
}
