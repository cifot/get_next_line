/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:34:32 by nharra            #+#    #+#             */
/*   Updated: 2019/09/11 16:58:25 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"
#include <stdlib.h>

t_dlist		*ft_dlist_push(t_dlist *lst, void *data, size_t size, int tag)
{
	t_dlist		*ptr;
	t_dlist		*end;

	if (data == NULL || size == 0 || !(ptr = (t_dlist *)malloc(sizeof(*ptr))))
		return (NULL);
	if (!(ptr->content = (t_dlist *)malloc(size)))
	{
		free(ptr);
		return (NULL);
	}
	ptr->tag = tag;
	ptr->next = NULL;
	if (lst == NULL)
	{
		ptr->prev = NULL;
		return (ptr);
	}
	end = lst;
	while (end->next)
		end = end->next;
	end->next = ptr;
	ptr->prev = end;
	return (lst);
}
