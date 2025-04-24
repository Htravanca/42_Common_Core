/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:16:56 by hepereir          #+#    #+#             */
/*   Updated: 2024/07/12 22:11:37 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				nodes;

	a = NULL;
	b = NULL;
	nodes = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
		a = ft_str_format(argv[1], a, b);
	if (argc >= 3)
		a = ft_argvs_format(argc, argv, a, b);
	nodes = ft_lsta_nok(a);
	if (nodes == 0)
		ft_error_msg(&a, &b);
	if (ft_is_lst_sorted(a) == 0)
		ft_sort_main(&a, &b, nodes);
	ft_clean_lst(&a);
	ft_clean_lst(&b);
}
