/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:17:10 by hepereir          #+#    #+#             */
/*   Updated: 2024/07/11 22:17:11 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_step(t_stack_node **a, t_stack_node **b)
{
	int	mean_val;

	mean_val = 0;
	while (ft_lst_size(*a) > 5)
	{
		mean_val = ft_mean_val(*a);
		if ((*a)->data <= mean_val)
			pb(a, b);
		else
			ra(a, 1);
	}
}

void	ft_bf_finder(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_b;
	t_stack_node	*temp_a;
	int				bf_found;
	int				aux_sub;
	int				prev_sub;

	temp_b = *b;
	while (temp_b)
	{
		temp_a = *a;
		bf_found = INT_MAX;
		prev_sub = INT_MAX;
		while (temp_a)
		{
			aux_sub = temp_a->data - temp_b->data;
			if (aux_sub > 0 && aux_sub < prev_sub)
			{
				bf_found = temp_a->data;
				prev_sub = aux_sub;
			}
			temp_a = temp_a->next;
		}
		temp_b->bf = bf_found;
		temp_b = temp_b->next;
	}
}

void	ft_find_and_exec(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_b;
	int				cost_sm;
	int				index;

	index = 0;
	cost_sm = INT_MAX;
	temp_b = *b;
	while (temp_b)
	{
		if (temp_b->cost->total_cost < cost_sm)
		{
			cost_sm = temp_b->cost->total_cost;
			index = temp_b->index;
		}
		temp_b = temp_b->next;
	}
	temp_b = *b;
	while (temp_b->index != index)
		temp_b = temp_b->next;
	ft_exec(a, b, temp_b);
}

void	ft_rotate_a(t_stack_node **a)
{
	int	aux_up;
	int	aux_dw;

	aux_up = 0;
	aux_dw = 0;
	while (ft_index_sm(*a) != 1)
	{
		aux_up = ft_index_sm(*a) - 1;
		aux_dw = ft_lst_size(*a) - ft_index_sm(*a) + 1;
		if (aux_up < aux_dw)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	ft_sort(t_stack_node **a, t_stack_node **b)
{
	ft_first_step(a, b);
	ft_sort_five(a, b);
	while (ft_lst_size(*b) > 0)
	{
		ft_bf_finder(a, b);
		ft_cost_calc(a, b);
		ft_find_and_exec(a, b);
		ft_cost_clean(b);
		pa(a, b);
	}
	ft_rotate_a(a);
}
