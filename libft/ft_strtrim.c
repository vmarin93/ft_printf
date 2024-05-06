/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:13:14 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/01 18:27:32 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	is_in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (s1[end - 1] && is_in_set(s1[end - 1], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	result = ft_calloc(sizeof(char), ((end - start) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		result[i] = s1[start + i];
		i++;
	}
	return (result);
}
