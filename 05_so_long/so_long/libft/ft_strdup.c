/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:07:32 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/11 19:22:00 by hepereir         ###   ########.fr       */
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
