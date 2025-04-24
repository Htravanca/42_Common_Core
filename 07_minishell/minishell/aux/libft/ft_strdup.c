/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:07:32 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/29 21:28:29 by jalves-v         ###   ########.fr       */
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
