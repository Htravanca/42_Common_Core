/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:07:28 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/22 19:53:17 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	j;

	j = 0;
	while (s[j] != (unsigned char)c && s[j])
	{
		j++;
	}
	if (s[j] == (unsigned char)c)
	{
		return ((char *)(s + j));
	}
	return (NULL);
}
