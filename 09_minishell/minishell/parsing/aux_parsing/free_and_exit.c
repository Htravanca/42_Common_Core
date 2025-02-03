/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:15:35 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:17:11 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(void)
{
	free_lst();
	ft_free_arr(get_shell()->env_arr);
	ft_lstclear_env(&get_shell()->env);
	ft_putstr_fd("Error creating lists.\n", 2);
	exit(1);
}

// final free to list and array of strings inside list
void	free_lst(void)
{
	t_tokens	*temp;
	t_tokens	*temp2;

	temp = get_shell()->tokens;
	while (temp)
	{
		temp2 = temp->next;
		free_redir(&temp->redir);
		free_arr2(temp->token);
		free(temp);
		temp = temp2;
	}
	get_shell()->tokens = NULL;
}

void	ft_free_err(char **arr, char *err)
{
	if (arr)
		ft_free_arr(arr);
	ft_free_arr(get_shell()->arr_2d);
	printf("%s\n", err);
}

void	free_redir(t_redir **redir)
{
	t_redir	*temp;

	if (!get_shell()->tokens || !*redir || !(*redir)->filename)
		return ;
	while (*redir)
	{
		temp = *redir;
		*redir = (*redir)->next;
		if (temp->filename)
		{
			free(temp->filename);
			temp->filename = NULL;
		}
		free(temp);
		temp = NULL;
	}
	*redir = NULL;
}

void	parsing_error(char *parsed)
{
	if (parsed)
		free(parsed);
	printf("Error parsing command line.\n");
	ft_lstclear_env(&get_shell()->env);
	ft_free_arr(get_shell()->env_arr);
	free_redir(&get_shell()->tokens->redir);
	rl_clear_history();
	exit(1);
}
