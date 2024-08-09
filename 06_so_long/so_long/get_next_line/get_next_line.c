/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:58:58 by hepereir          #+#    #+#             */
/*   Updated: 2024/08/09 12:01:07 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*stash;
	static char	buffer[BUFFER_SIZE + 1];
	int			read_bytes;

	read_bytes = 0;
	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[0])
		stash = ft_strjoin_gnl(stash, buffer);
	while (ft_is_newline(buffer))
	{
		ft_trim(buffer, stash, 0);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes != BUFFER_SIZE)
		{
			stash = ft_aux(stash, buffer, read_bytes);
			break ;
		}
		else
			stash = ft_strjoin_gnl(stash, buffer);
	}
	ft_trim(buffer, stash, 1);
	return (stash);
}
