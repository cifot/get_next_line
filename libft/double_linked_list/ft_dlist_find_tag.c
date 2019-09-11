/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_find_tag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:40:55 by nharra            #+#    #+#             */
/*   Updated: 2019/09/11 12:44:23 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlist_find_tag(t_dlist *lst, int tag)
{
	if (lst == NULL)
		return (NULL);
	while (lst && (lst->tag != tag))
	{
		lst = lst->next;
	}
	return (lst);
}
