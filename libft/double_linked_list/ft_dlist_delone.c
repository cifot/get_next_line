/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:56:23 by nharra            #+#    #+#             */
/*   Updated: 2019/09/11 13:13:25 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlist_delone(t_dlist *lst, void (*del)(void *))
{
	if (lst)
	{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
		del(lst->content);
	}
}
