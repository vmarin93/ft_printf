/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:42:13 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/01 18:17:02 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	i;

	duplicate = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		duplicate[i] = s[i];
		i++;
	}
	return (duplicate);
}
