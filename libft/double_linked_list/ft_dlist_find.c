/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:49:13 by nharra            #+#    #+#             */
/*   Updated: 2019/09/11 12:43:50 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlist_find(t_dlist *lst, void *data, int (*f)(void *, void *))
{
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst && f(lst->content, data))
	{
		lst = lst->next;
	}
	return (lst);
}
