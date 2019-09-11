/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:18:10 by nharra            #+#    #+#             */
/*   Updated: 2019/09/11 21:04:22 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dlist.h"
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

int		make_str(char *str, char **line, char **find_chr)
{
	*find_chr = ft_strchr(str, '\n');
	if (*find_chr)
		**find_chr = '\0';
	if (!ft_safe_strcat(line, str))
		return (-1);
	return (0);
}

int		ft_read_from_fd(t_dlist *lst, const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		res;
	char	*find_chr;

	find_chr = NULL;
	while ((res = read(fd, buf, BUFF_SIZE)))
	{
		if (res == -1)
			return (-1);
		buf[res] = '\0';
		make_str(buf, line, &find_chr);
		if (find_chr)
		{
			ft_dlist_push(lst, find_chr + 1, ft_strlen(find_chr + 1) + 1, fd);
			return (1);
		}
	}
	return (0);
}

int		ft_read_from_lst(t_dlist *ptr, char **line)
{
	char	*find_chr;
	char	*new;

	find_chr = NULL;
	if (make_str((char *)ptr->content, line, &find_chr))
		return (-1);
	if (find_chr == NULL)
	{
		ft_dlist_simple_delone(ptr);
		return (0);
	}
	else
	{
		if (!(new = (char *)malloc(ft_strlen(find_chr + 1))))
			return (-1);
		ft_strcpy(new, find_chr + 1);
		free(ptr->content);
		ptr->content = new;
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_dlist	*lst;
	t_dlist			*current;
	int				res;

	if (!line || !(*line = ft_memalloc(1)))
		return (-1);
	current = ft_dlist_find_tag(lst, fd);
	if (current)
	{
		printf("*%s*\n", current->content);
		if ((res = ft_read_from_lst(current, line)) == -1)
			return (-1);
		if (res == 0)
			return (ft_read_from_fd(lst, fd, line));
		else
			return (1);
	}
	else
	{
		return (ft_read_from_fd(lst, fd, line));
	}
}
