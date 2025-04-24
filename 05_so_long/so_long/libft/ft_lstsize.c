/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:10:52 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/24 20:12:26 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*pointer;

	if (!lst)
		return (0);
	pointer = lst->next;
	count = 1;
	while (pointer)
	{
		count++;
		pointer = pointer->next;
	}
	return (count);
}
