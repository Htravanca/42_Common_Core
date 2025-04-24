/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:06:05 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/15 19:02:18 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*j;
	size_t	max;

	max = nmemb * size;
	if (nmemb && size && (max / size != nmemb))
		return (NULL);
	j = malloc(max);
	if (!j)
		return (NULL);
	ft_bzero(j, max);
	return (j);
}
