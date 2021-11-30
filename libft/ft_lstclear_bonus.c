/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:39:39 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/17 16:47:13 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *supp;

	if (lst == NULL || del == NULL)
		return ;
	tmp = *lst;
	while (tmp != 0)
	{
		(*del)(tmp->content);
		supp = tmp;
		tmp = tmp->next;
		free(supp);
	}
	lst = NULL;
}
