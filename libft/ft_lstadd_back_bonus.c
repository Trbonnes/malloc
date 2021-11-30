/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:19:29 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/17 18:53:55 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (alst == NULL || new == NULL)
		return ;
	tmp = *alst;
	if (tmp != 0)
	{
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}
