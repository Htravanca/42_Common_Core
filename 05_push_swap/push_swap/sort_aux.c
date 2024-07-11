/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:17:04 by hepereir          #+#    #+#             */
/*   Updated: 2024/07/11 22:17:05 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_bg(t_stack_node *lst)
{
	long			nb;
	t_stack_node	*temp;
	int				index;

	nb = (long)INT_MIN - 1;
	temp = lst;
	index = 0;
	while (temp)
	{
		if (nb < temp->data)
		{
			nb = temp->data;
			index = temp->index;
		}
		temp = temp->next;
	}
	return (index);
}

int	ft_index_sm(t_stack_node *lst)
{
	long			nb;
	t_stack_node	*temp;
	int				index;

	nb = (long)INT_MAX + 1;
	temp = lst;
	index = 0;
	while (temp)
	{
		if (nb > temp->data)
		{
			nb = temp->data;
			index = temp->index;
		}
		temp = temp->next;
	}
	return (index);
}

int	ft_mean_val(t_stack_node *a)
{
	long long		sum;
	int				size;
	int				result;
	t_stack_node	*temp;

	sum = 0;
	temp = a;
	while (temp)
	{
		sum += temp->data;
		temp = temp->next;
	}
	if (sum == 0)
		return (0);
	size = ft_lst_size(a);
	result = sum / size;
	return (result);
}

void	ft_exec_aux(t_stack_node **a, t_stack_node **b, t_stack_node *temp_b)
{
	while (temp_b->cost->rra)
	{
		rra(a, 1);
		temp_b->cost->rra--;
	}
	while (temp_b->cost->rrb)
	{
		rrb(b, 1);
		temp_b->cost->rrb--;
	}
}

void	ft_exec(t_stack_node **a, t_stack_node **b, t_stack_node *temp_b)
{
	while (temp_b->cost->rr)
	{
		rr(a, b);
		temp_b->cost->rr--;
	}
	while (temp_b->cost->rrr)
	{
		rrr(a, b);
		temp_b->cost->rrr--;
	}
	while (temp_b->cost->ra)
	{
		ra(a, 1);
		temp_b->cost->ra--;
	}
	while (temp_b->cost->rb)
	{
		rb(b, 1);
		temp_b->cost->rb--;
	}
	ft_exec_aux(a, b, temp_b);
}
