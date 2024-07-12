/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:16:12 by hepereir          #+#    #+#             */
/*   Updated: 2024/07/11 22:16:18 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost_clean(t_stack_node **b)
{
	t_stack_node	*temp_b;

	temp_b = *b;
	while (temp_b)
	{
		temp_b->bf = 0;
		temp_b->cost->ra = 0;
		temp_b->cost->rb = 0;
		temp_b->cost->rr = 0;
		temp_b->cost->rra = 0;
		temp_b->cost->rrb = 0;
		temp_b->cost->rrr = 0;
		temp_b->cost->total_cost = 0;
		temp_b = temp_b->next;
	}
}

void	ft_error_msg(t_stack_node **a, t_stack_node **b)
{
	write(2, "Error\n", 6);
	ft_clean_lst(a);
	ft_clean_lst(b);
	exit(0);
}

void	ft_clean_lst(t_stack_node **lst)
{
	t_stack_node	*temp;
	t_stack_node	*next;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		if (temp->cost)
			free(temp->cost);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
