/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 08:41:51 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/15 15:16:44 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static int			ft_scrollup(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (set[i] != '\0')
	{
		if (s1[j] == set[i])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

static int			ft_scrolldown(char const *s1, char const *set)
{
	int i;
	int k;

	i = 0;
	k = ft_strlen(s1) - 1;
	while (set[i] != '\0')
	{
		if (s1[k] == set[i])
		{
			if (k - 1 < 0)
				return (k);
			k--;
			i = 0;
		}
		else
			i++;
	}
	return (k);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char		*dest;
	int			i;
	int			j;
	int			k;

	if (s1 == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	j = ft_scrollup(s1, set);
	k = ft_scrolldown(s1, set);
	i = 0;
	while (j <= k)
	{
		dest[i] = s1[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
