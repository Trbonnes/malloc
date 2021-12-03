/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:01:06 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/21 09:05:13 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	char	*dest;
	char	*s;

	s = (char *)src;
	dest = dst;
	i = 0;
	while (i++ < size && *dest != '\0')
		dest++;
	len = dest - dst;
	if (size - len == 0)
		return (len + ft_strlen(src));
	i = len;
	while (*s != '\0')
	{
		if (i++ < size - 1)
		{
			*dest = *s;
			dest++;
		}
		s++;
	}
	*dest = '\0';
	return (len + s - src);
}
