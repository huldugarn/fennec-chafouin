/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <rle-corr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 14:07:07 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/15 12:34:32 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*src_copy;

	src_copy = (char*)malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (src_copy == NULL)
		return (NULL);
	ft_strcpy(src_copy, src);
	return (src_copy);
}
