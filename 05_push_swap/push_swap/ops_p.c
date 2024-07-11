/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:16:43 by hepereir          #+#    #+#             */
/*   Updated: 2024/07/11 22:16:44 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_index(t_stack_node **lst)
{
	t_stack_node	*temp;
	int				i;

	i = 1;
	temp = (*lst);
	while (temp)
	{
		(temp)->index = i;
		i++;
		(temp) = (temp)->next;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (!(*b))
		return ;
	temp = (*a);
	(*a) = (*b);
	(*b) = (*b)->next;
	(*a)->next = temp;
	ft_update_index(a);
	ft_update_index(b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (!(*a))
		return ;
	temp = (*b);
	(*b) = (*a);
	(*a) = (*a)->next;
	(*b)->next = temp;
	ft_update_index(a);
	ft_update_index(b);
	write(1, "pb\n", 3);
}
