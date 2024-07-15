/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:58:58 by hepereir          #+#    #+#             */
/*   Updated: 2024/05/21 20:54:24 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*stash;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			read_bytes;

	read_bytes = 0;
	stash = NULL;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[fd][0])
		stash = ft_strjoin(stash, buffer[fd]);
	while (ft_is_newline(buffer[fd]))
	{
		ft_trim(buffer[fd], stash, 0);
		read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_bytes != BUFFER_SIZE)
		{
			stash = ft_aux(stash, buffer[fd], read_bytes);
			break ;
		}
		else
			stash = ft_strjoin(stash, buffer[fd]);
	}
	ft_trim(buffer[fd], stash, 1);
	return (stash);
}
