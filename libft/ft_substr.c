/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:43:13 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/15 15:07:13 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int		ft_strlen(char *c)
{
	unsigned int i;

	i = 0;
	while (*c++)
		i++;
	return (i);
}

char					*ft_substr(char const *s,
unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	if (ft_strlen((char*)s) <= start)
	{
		substr[0] = '\0';
		return (substr);
	}
	s += start;
	i = 0;
	while (len > 0 && *s)
	{
		substr[i] = *s;
		s++;
		i++;
		len--;
	}
	substr[i] = 0;
	return (substr);
}
