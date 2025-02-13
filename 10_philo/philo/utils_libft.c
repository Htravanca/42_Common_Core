/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:25:09 by hepereir          #+#    #+#             */
/*   Updated: 2025/02/13 15:26:33 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalldigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

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
