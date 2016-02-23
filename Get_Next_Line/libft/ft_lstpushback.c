/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:20:49 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/23 16:24:53 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushback(t_list **list, t_list *new)
{
	t_list	*cursor;

	cursor = *list;
	if (*list == NULL)
		*list = new;
	else
	{
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = new;
	}
	return (*list);
}
