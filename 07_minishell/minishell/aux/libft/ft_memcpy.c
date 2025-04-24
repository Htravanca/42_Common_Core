/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:06:56 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/20 17:57:55 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!src && !dest)
		return (NULL);
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	while (n > 0)
	{
		a[n - 1] = b[n - 1];
		n--;
	}
	return (dest);
}
