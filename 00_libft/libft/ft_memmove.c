/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:07:01 by hepereir          #+#    #+#             */
/*   Updated: 2024/11/23 17:28:51 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;
	size_t				a;

	if (!src && !dest)
		return (NULL);
	a = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (s > d)
	{
		while (n > a)
		{
			d[a] = s[a];
			a++;
		}
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dest);
}
