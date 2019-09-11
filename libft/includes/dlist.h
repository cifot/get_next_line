/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:11:54 by nharra            #+#    #+#             */
/*   Updated: 2019/09/11 13:13:00 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H
# include <string.h>

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	int				tag;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;
void				ft_dlist_delone(t_dlist *lst, void (*del)(void *));
void				ft_dlist_del(t_dlist **lst, void (*del)(void *));
t_dlist				*ft_dlist_find(t_dlist *lst, void *data, int (*f)(void *, void *));
t_dlist				*ft_dlist_push(t_dlist *lst, void *data, size_t size, int tag);
void				ft_dlist_simple_delone(t_dlist *lst);
void				ft_dlist_simple_del(t_dlist **lst);
t_dlist				*ft_dlist_find_tag(t_dlist *lst, int tag);

#endif
