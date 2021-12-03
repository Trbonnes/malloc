/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:58:08 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/13 15:00:44 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static int	ft_size(int tmp, int size)
{
	while (tmp > 0)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}

static char	*ft_zero(void)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_fullup(int tmp, int size, int neg, int n)
{
	char	*str;
	int		i;

	if (n == 0)
		str = ft_zero();
	else
	{
		if (!(str = malloc(sizeof(char) * size + 1)))
			return (NULL);
		i = size - 1;
		if (neg == -2)
			str[i--] = '8';
		while (tmp > 0)
		{
			str[i--] = ((tmp % 10) + '0');
			tmp = tmp / 10;
		}
		if (neg < 0)
			str[0] = '-';
		str[size] = '\0';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		size;
	int		tmp;

	neg = 1;
	size = 0;
	if (n == -2147483648)
	{
		n = 214748364;
		size = size + 2;
		neg = -2;
	}
	if (n < 0)
	{
		neg = -1;
		n = -n;
		size++;
	}
	tmp = n;
	size = ft_size(tmp, size);
	str = ft_fullup(tmp, size, neg, n);
	return (str);
}
