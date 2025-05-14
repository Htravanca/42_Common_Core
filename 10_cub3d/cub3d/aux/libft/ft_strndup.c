/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:07:32 by hepereir          #+#    #+#             */
/*   Updated: 2025/03/28 19:17:49 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	j;
	char	*new;

	j = 0;
	new = (char *)malloc((n + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[j] && j < n)
	{
		new[j] = s[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
