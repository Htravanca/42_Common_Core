/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:18:18 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/03 21:18:22 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	sl;
	size_t	j;
	char	*new;

	j = 0;
	sl = ft_strlen(s);
	new = (char *)malloc((sl + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (j < sl)
	{
		new[j] = s[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
