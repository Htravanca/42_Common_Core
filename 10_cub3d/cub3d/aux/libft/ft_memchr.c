/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:06:48 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/23 19:53:53 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			j;

	j = 0;
	src = (unsigned char *)s;
	if (n)
	{
		while (src[j] != (unsigned char)c && j < (n - 1))
			j++;
		if (src[j] == (unsigned char)c)
			return ((void *)((char *)s + j));
	}
	return (NULL);
}
