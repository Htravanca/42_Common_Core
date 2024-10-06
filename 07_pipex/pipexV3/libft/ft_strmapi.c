/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:08:32 by hepereir          #+#    #+#             */
/*   Updated: 2024/04/11 19:22:49 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cpy;
	unsigned int	len;
	unsigned int	j;

	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (j < len)
	{
		cpy[j] = f(j, s[j]);
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
