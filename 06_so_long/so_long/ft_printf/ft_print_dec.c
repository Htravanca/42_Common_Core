/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:03:29 by hepereir          #+#    #+#             */
/*   Updated: 2024/05/01 13:01:07 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_len(long nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_print_dec(long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_print_dec(nb / 10);
		ft_print_dec(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

int	ft_print_d(int nb)
{
	ft_print_dec(nb);
	return (ft_dec_len(nb));
}

int	ft_print_u(unsigned int nb)
{
	ft_print_dec(nb);
	return (ft_dec_len(nb));
}
