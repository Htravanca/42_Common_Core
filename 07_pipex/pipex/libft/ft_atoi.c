/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:05:36 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/21 15:29:09 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	pos;
	int		sign;
	int		nb;

	nb = 0;
	sign = 1;
	pos = 0;
	while (((nptr[pos] >= 9 && nptr[pos] <= 13) || nptr[pos] == 32)
		&& nptr[pos])
		pos++;
	if ((nptr[pos] == '-' || nptr[pos] == '+') && nptr[pos])
	{
		if (nptr[pos] == '-')
			sign = -1;
		pos++;
	}
	while (nptr[pos] >= '0' && nptr[pos] <= '9' && nptr[pos])
	{
		nb = nb * 10 + (nptr[pos] - 48);
		pos++;
	}
	return (sign * nb);
}
