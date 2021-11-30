/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:07:16 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/21 08:54:40 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strrchr(const char *s, int c)
{
	const char *end_s;

	end_s = 0;
	while (*s)
	{
		if (*s == c)
			end_s = s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return ((char *)end_s);
}
