/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:06:31 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/11 16:38:53 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int	ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	if (lst != 0)
	{
		while (lst != 0)
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}
