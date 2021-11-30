/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:51:58 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/10 10:46:02 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptrd;
	const char		*ptrs;

	ptrd = dst;
	ptrs = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*ptrd = *ptrs;
		ptrd++;
		ptrs++;
		n--;
	}
	return (dst);
}
