/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:06:35 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/11 19:00:32 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_size(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int	ft_auxiliar(int n, char *nb, size_t *size)
{
	if (n == -2147483648)
	{
		nb[*size - 1] = '8';
		nb[0] = '-';
		*size = *size - 1;
		n = 214748364;
	}
	else if (n < 0)
	{
		nb[0] = '-';
		n = -n;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*nb;

	size = ft_check_size(n);
	nb = (char *)malloc((size + 1) * sizeof(char));
	if (!nb)
		return (NULL);
	nb[size] = '\0';
	n = ft_auxiliar(n, nb, &size);
	if (n == 0)
	{
		nb[0] = '0';
	}
	else
	{
		while (n)
		{
			nb[size - 1] = n % 10 + 48;
			n /= 10;
			size--;
		}
	}
	return (nb);
}
