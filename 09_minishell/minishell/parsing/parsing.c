/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:48:52 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/29 21:14:39 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	split_spaces(void)
{
	static int	i;
	char		**arr_split;

	arr_split = NULL;
	arr_split = ft_split(get_shell()->arr_2d[i], '\2');
	if (!arr_split)
	{
		ft_free_arr(get_shell()->arr_2d);
		parsing_error(NULL);
	}
	populate_lst(arr_split);
	if (get_shell()->arr_2d[++i])
		split_spaces();
	i = 0;
}

static char	**split_2d_arr(char *parsed)
{
	char	**arr_2d;

	arr_2d = ft_split(parsed, '\3');
	if (!arr_2d)
		return (NULL);
	return (arr_2d);
}

static int	check_input(char c, char **replaced)
{
	char	*temp;

	temp = NULL;
	if (is_whitespace(c))
	{
		temp = add_char(*replaced, '\2');
		if (!temp)
			return (-1);
		*replaced = temp;
	}
	else if (c == '|')
	{
		temp = add_char(*replaced, '\3');
		if (!temp)
			return (-1);
		*replaced = temp;
	}
	else
	{
		temp = add_char(*replaced, c);
		if (!temp)
			return (-1);
		*replaced = temp;
	}
	return (check_input_aux(*replaced));
}

static char	*replace_chars(char *cmd, char *replaced, char *temp)
{
	while (*cmd)
	{
		if (*cmd == '\'' || *cmd == '\"')
		{
			temp = parse_quotes(replaced, &cmd);
			if (temp == NULL)
				return (free(replaced), NULL);
			replaced = temp;
			continue ;
		}
		else if (*cmd == '<' || *cmd == '>')
		{
			temp = parse_redir(replaced, &cmd);
			if (temp == NULL)
				return (free(replaced), NULL);
			replaced = temp;
			continue ;
		}
		else if (check_input(*cmd, &replaced) == -1)
			return (NULL);
		cmd++;
	}
	return (replaced);
}

void	parse_input(char *cmd)
{
	char	*parsed;
	char	**arr_2d;
	int		len;
	char	*replaced;
	char	*temp;

	len = ft_strlen(cmd);
	if (len == 0)
		return ;
	replaced = NULL;
	temp = NULL;
	parsed = replace_chars(cmd, replaced, temp);
	if (!parsed)
		parsing_error(parsed);
	arr_2d = split_2d_arr(parsed);
	if (!arr_2d)
		parsing_error(parsed);
	free(parsed);
	get_shell()->arr_2d = arr_2d;
	split_spaces();
	free_arr2(get_shell()->arr_2d);
	expand_tokens();
	check_quotes_tokens();
	check_list();
}
