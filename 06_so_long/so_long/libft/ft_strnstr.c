/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:08:46 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/15 18:54:21 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t n)
{
	size_t	j;
	size_t	t;

	t = 0;
	j = 0;
	if (!haystack && n == 0)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[j] && j < n)
	{
		while (haystack[j + t] == needle[t] && (j + t) < n)
		{
			if (needle[t + 1] == '\0')
				return ((char *)&haystack[j]);
			t++;
		}
		t = 0;
		j++;
	}
	return (NULL);
}
