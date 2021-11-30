/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:50:01 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/17 18:53:38 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_delete(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *supp;

	if (lst == NULL || del == NULL)
		return (NULL);
	tmp = *lst;
	while (tmp != 0)
	{
		(*del)(tmp->content);
		supp = tmp;
		tmp = tmp->next;
		free(supp);
	}
	lst = NULL;
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	t_list *new;

	if (lst == NULL || f == NULL || del == NULL)
		return (lst);
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = (*f)(lst->content);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = malloc(sizeof(t_list))))
			return (ft_delete(&tmp, del));
		new = new->next;
		new->content = (*f)(lst->content);
		lst = lst->next;
	}
	new->next = NULL;
	return (tmp);
}
