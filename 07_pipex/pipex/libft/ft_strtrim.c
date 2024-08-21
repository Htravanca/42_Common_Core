/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:08:54 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/16 18:16:59 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char c, char const *set)
{
	size_t	k;

	k = 0;
	while (set[k])
	{
		if (set[k] == c)
		{
			return (1);
		}
		k++;
	}
	return (0);
}

static char	*ft_check_limits(char const *s1, char const *set, size_t *k)
{
	char	*begin;
	char	*end;
	size_t	j;

	j = 0;
	begin = (char *)&s1[0];
	while (ft_check_char(s1[j], set) && s1[j])
	{
		begin = (char *)&s1[j + 1];
		j++;
	}
	if (*begin == '\0')
	{
		*k = 0;
		return (begin);
	}
	j = ft_strlen(s1) - 1;
	end = (char *)&s1[j];
	while (ft_check_char(s1[j], set) && j > 0)
	{
		end = (char *)&s1[j - 1];
		j--;
	}
	*k = end - begin + 1;
	return (begin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*begin;
	size_t	k;
	size_t	j;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	k = 0;
	begin = ft_check_limits(s1, set, &k);
	result = (char *)malloc((k + 1) * sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	while (j < k)
	{
		result[j] = begin[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}
