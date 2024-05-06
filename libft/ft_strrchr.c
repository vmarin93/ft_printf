/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:33:06 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/01 18:29:01 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	to_find;

	to_find = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == to_find)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
