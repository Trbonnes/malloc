/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:08:04 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/21 09:10:53 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (s1[0] == '\0')
		return (0);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && (i + j) < len && s1[i + j] != '\0')
			{
				if (s2[j + 1] == '\0')
					return ((char *)(s1 + i));
				j++;
			}
		}
		i++;
	}
	return (0);
}
