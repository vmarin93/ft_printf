/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:28:36 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/01 18:16:42 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	get_matrix_size(char const *s, char c)
{
	int	matrix_size;
	int	flag;
	int	i;

	matrix_size = 0;
	flag = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			matrix_size++;
		}
		i++;
	}
	return (matrix_size);
}

static void	fill_matrix(char const *s, char c, char **matrix)
{
	int		offset;
	size_t	i;
	size_t	j;

	offset = -1;
	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && offset < 0)
			offset = i;
		else if ((s[i] == c || i == ft_strlen(s)) && offset >= 0)
		{
			matrix[j] = ft_substr(s, offset, i - offset);
			offset = -1;
			j++;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;

	if (!s)
		return (NULL);
	matrix = ft_calloc(get_matrix_size(s, c) + 1, sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	fill_matrix(s, c, matrix);
	return (matrix);
}
