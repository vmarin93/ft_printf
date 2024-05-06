/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:01:36 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/02 16:28:17 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;
	char	to_find;

	to_find = (char)c;
	len = ft_strlen(s);
	i = 0;
	while (i < len + 1)
	{
		if (s[i] == to_find)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
