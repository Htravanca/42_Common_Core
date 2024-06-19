/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:07:44 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/16 18:17:56 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	total_len;
	size_t	i;

	i = 0;
	dest_len = 0;
	if (!dest && !size)
		return (0);
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	if (dest_len < size)
		total_len = dest_len + ft_strlen(src);
	else
		return (size + ft_strlen(src));
	while (dest_len < (size - 1) && src[i])
	{
		dest[dest_len] = src[i];
		i++;
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (total_len);
}
