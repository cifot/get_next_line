/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_strcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:52:15 by nharra            #+#    #+#             */
/*   Updated: 2019/09/12 10:49:14 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_safe_strcat(char **dest, const char *src)
{
	char	*new;
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(*dest);
	src_size = ft_strlen(src);
	if (src_size == 0)
		return (*dest);
	if (!(new = (char *)malloc(dest_size + src_size + 1)))
	{
		return (NULL);
	}
	ft_strcpy(new, *dest);
	free(*dest);
	*dest = new;
	return (ft_strcat(new + dest_size, src));
}
