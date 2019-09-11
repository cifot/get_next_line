/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:20:34 by nharra            #+#    #+#             */
/*   Updated: 2019/09/11 16:14:26 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlist_del(t_dlist **lst, void (*del)(void *))
{
	t_dlist *ptr;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		ft_dlist_delone(ptr, del);
	}
	*lst = NULL;
}
