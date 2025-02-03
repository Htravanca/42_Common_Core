/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:08:49 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/22 19:57:50 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	j;

	j = ft_strlen(s);
	while (s[j] != (unsigned char)c && j > 0)
	{
		j--;
	}
	if (s[j] == (unsigned char)c)
	{
		return ((char *)s + j);
	}
	return (NULL);
}
