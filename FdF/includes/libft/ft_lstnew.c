/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:43:54 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/12 16:07:01 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*additional_elem;

	additional_elem = (t_list *)malloc(sizeof(t_list) * 1);
	if (additional_elem == NULL)
		return (NULL);
	if (content == NULL)
	{
		additional_elem->content = NULL;
		additional_elem->content_size = 0;
	}
	else
	{
		additional_elem->content = malloc(content_size);
		if (additional_elem->content == NULL)
			return (NULL);
		ft_memmove(additional_elem->content, content, content_size);
		additional_elem->content_size = content_size;
	}
	additional_elem->next = NULL;
	return (additional_elem);
}
