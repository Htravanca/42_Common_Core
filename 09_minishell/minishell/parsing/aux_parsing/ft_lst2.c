/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:47:28 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:16:58 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*lst_redir(void)
{
	t_redir	*redir;

	redir = ft_calloc(sizeof(t_redir), 1);
	if (!redir)
		return (NULL);
	redir->next = NULL;
	return (redir);
}

void	ft_lstadd_back_redir(t_redir **lst, t_redir *new)
{
	t_redir	*temp;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
