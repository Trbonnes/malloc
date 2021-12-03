/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:52:41 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/21 09:02:10 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t n)
{
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	if (!dest || !src)
		return (0);
	while (src[count] != '\0')
		count++;
	if (n == 0)
		return (count);
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 1)
		dest[i] = '\0';
	return (count);
}
