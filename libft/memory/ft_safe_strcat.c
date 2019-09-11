/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_strcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:52:15 by nharra            #+#    #+#             */
/*   Updated: 2019/09/11 17:20:36 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_safe_strcat(char **dest, const char *src)
{
	char	*new;
	size_t	dest_line;

	dest_line = ft_strlen(*dest);
	if (!(new = (char *)malloc(dest_line + ft_strlen(src) + 1)))
	{
		return (NULL);
	}
	ft_strcpy(new, *dest);
	free(*dest);
	*dest = new;
	return (strcat(new + dest_line, src));
}
