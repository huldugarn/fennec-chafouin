/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:08:00 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/12 15:52:24 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map_list;

	if (lst != NULL && f != NULL)
	{
		map_list = f(lst);
		if (map_list != NULL && lst->next != NULL)
			map_list->next = ft_lstmap(lst->next, f);
		return (map_list);
	}
	return (NULL);
}
