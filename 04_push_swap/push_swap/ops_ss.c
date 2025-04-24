/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_ss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:16:51 by hepereir          #+#    #+#             */
/*   Updated: 2024/07/11 22:16:52 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a, int print)
{
	t_stack_node	*temp;
	t_stack_node	*temp_next;

	if (!(*a) || !((*a)->next))
		return ;
	temp = (*a);
	temp_next = (*a)->next->next;
	*a = (*a)->next;
	(*a)->next = temp;
	(*a)->next->next = temp_next;
	ft_update_index(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, int print)
{
	t_stack_node	*temp;
	t_stack_node	*temp_next;

	if (!(*b) || !((*b)->next))
		return ;
	temp = (*b);
	temp_next = (*b)->next->next;
	*b = (*b)->next;
	(*b)->next = temp;
	(*b)->next->next = temp_next;
	ft_update_index(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	if (!(*b) || !((*b)->next) || !(*a) || !((*a)->next))
		return ;
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
