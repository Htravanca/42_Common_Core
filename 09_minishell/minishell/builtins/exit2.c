/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:31:28 by hepereir          #+#    #+#             */
/*   Updated: 2025/01/29 21:41:41 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit3(t_tokens *tokens, int in, int out)
{
	ft_putstr_fd("exit\n", out);
	ft_putstr_fd("exit: ", out);
	ft_putstr_fd(tokens->token[1], out);
	ft_putstr_fd(": numeric argument required\n", out);
	ft_finish(tokens, in, out);
	exit(2);
}
