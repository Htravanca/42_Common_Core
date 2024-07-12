/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:16:53 by hepereir          #+#    #+#             */
/*   Updated: 2024/07/12 22:12:28 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (((-result) < (long)INT_MIN && sign == -1) || (result > (long)INT_MAX
				&& sign == 1))
			return ((long)INT_MAX + 1);
		i++;
	}
	return (result * sign);
}

int	ft_nb_str_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'
					|| str[i] == '+'))
				return (0);
			if ((str[i] == '-' || str[i] == '+') && !(str[1] >= '0'
					&& str[1] <= '9'))
				return (0);
		}
		else
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_parsing_aux(t_stack_node **a, char *arr, int pos)
{
	long	nb;
	long	error;

	error = (long)INT_MAX + 1;
	nb = ft_atoi(arr);
	if (nb == error)
		return (0);
	ft_lstadd_back(a, nb, pos);
	return (1);
}

t_stack_node	*ft_argvs_format(int argc, char **argv, t_stack_node *a,
		t_stack_node *b)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_nb_str_valid(argv[i]) && ft_parsing_aux(&a, argv[i], i))
			i++;
		else
			ft_error_msg(&a, &b);
	}
	return (a);
}

t_stack_node	*ft_str_format(char *str, t_stack_node *a, t_stack_node *b)
{
	char	**arr;
	int		elem;
	int		j;

	j = 0;
	elem = 0;
	arr = ft_split(str, ' ');
	while (arr[elem])
		elem++;
	while (j < elem)
	{
		if (ft_nb_str_valid(arr[j]) && ft_parsing_aux(&a, arr[j], j + 1))
			j++;
		else
		{
			ft_free(arr, elem);
			ft_error_msg(&a, &b);
		}
	}
	ft_free(arr, elem);
	return (a);
}
