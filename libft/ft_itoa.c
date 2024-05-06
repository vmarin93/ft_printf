/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:08:05 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/01 18:15:56 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	get_int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n > 0)
		n *= -1;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = ft_calloc(get_int_len(n) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	i = get_int_len(n) - 1;
	if (n > 0)
	{
		n *= -1;
	}
	while (n != 0)
	{
		str[i] = -(n % 10) + '0';
		i--;
		n /= 10;
	}
	return (str);
}
