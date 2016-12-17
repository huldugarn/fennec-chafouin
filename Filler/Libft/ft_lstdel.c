/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:12:36 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/12 15:55:49 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p_cursor;
	t_list	*p_tmp;

	p_cursor = *alst;
	while (p_cursor)
	{
		p_tmp = p_cursor->next;
		del(p_cursor->content, p_cursor->content_size);
		free(p_cursor);
		p_cursor = p_tmp;
	}
	*alst = NULL;
}
