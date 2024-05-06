/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:11:12 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/02 20:17:33 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*travel;

	if (!lst)
		return (NULL);
	travel = lst;
	while (travel->next != NULL)
		travel = travel->next;
	return (travel);
}
