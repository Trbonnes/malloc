/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:54:01 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/15 15:55:42 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static int	ft_count(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static int	ft_next(char const *str, char c, int i)
{
	if (i == 0 && str[i] != c && str[i])
		return (i);
	while (str[i] != c && str[i])
		i++;
	while (str[i] == c && str[i])
		i++;
	return (i);
}

static int	ft_length(char const *str, char c, int i)
{
	int length;

	length = 0;
	while (str[i + length] != c && str[i + length])
		length++;
	return (length);
}

char		**ft_split(char const *str, char c)
{
	char	**tab;
	int		count;
	int		s;
	int		i;
	int		j;

	count = ft_count(str, c);
	if (!(tab = malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	s = 0;
	while (i < count && str[s])
	{
		s = ft_next(str, c, s);
		j = 0;
		if (!(tab[i] = malloc(sizeof(char) * (ft_length(str, c, s) + 1))))
			return (NULL);
		while (str[s] != c && str[s])
			tab[i][j++] = str[s++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
