/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 08:27:10 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/21 08:42:30 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	char		*end_d;
	const char	*end_s;

	d = dst;
	s = src;
	end_d = d + (n - 1);
	end_s = s + (n - 1);
	if (dst == 0 && src == 0)
		return (NULL);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			*end_d-- = *end_s--;
	return (dst);
}
